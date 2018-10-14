/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_converter_pthird.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:40:11 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/26 15:55:56 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define UI unsigned int

static void	ft_cmp_big_size_0b(int v, char *str)
{
	*(str + 3) = (v & 63) | 128;
	*(str + 2) = ((v >> 6) & 63) | 128;
	*(str + 1) = ((v >> 12) & 63) | 128;
	*str = ((v >> 18) & 63) | 240;
}

static char	*ft_cmp_size_0b(int n_bits, int v)
{
	char	*str;

	if (n_bits <= 11)
	{
		str = ft_strnew(2);
		*str = (v >> 6) | 192;
		*(str + 1) = (v & 63) | 128;
	}
	else if (n_bits <= 16)
	{
		str = ft_strnew(3);
		*(str + 2) = (v & 63) | 128;
		*(str + 1) = ((v >> 6) & 63) | 128;
		*str = (v >> 12) | 224;
	}
	else if (v <= 0xFFFF)
	{
		str = ft_strnew(4);
		ft_cmp_big_size_0b(v, str);
	}
	else
		str = ft_strnew(1);
	return (str);
}

int			str_wchar(int value, t_flag **spec_f)
{
	UI		n_bits;
	int		temp;
	char	*str;
	char	*z;

	n_bits = 0;
	temp = value;
	while (temp > 0)
	{
		temp = temp >> 1;
		n_bits++;
	}
	if (value > 127 && n_bits > 0)
	{
		str = ft_cmp_size_0b(n_bits, value);
		(*spec_f)->value = str;
	}
	else if (value <= 127)
	{
		z = ft_strnew(1);
		*z = value;
		(*spec_f)->value = z;
	}
	return (1);
}

void		va_arg_wchar_t(t_flag **spec_f, va_list list)
{
	char	*ptr;
	int		value;

	value = va_arg(list, int);
	if (MB_CUR_MAX == 1 || !str_wchar(value, &(*spec_f)))
	{
		ptr = ft_strnew(1);
		*ptr = -1;
		(*spec_f)->value = ptr;
	}
}
