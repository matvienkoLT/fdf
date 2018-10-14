/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:08:04 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/21 10:06:56 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ULLI unsigned long long int

void	va_arg_int(t_flag **spec_f, va_list list)
{
	long long int	value;

	if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "hh"))
		value = (char)va_arg(list, int);
	else if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "h"))
		value = (short int)va_arg(list, int);
	else if (((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "l")) ||
		((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "ll")) ||
		((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "j")))
		value = va_arg(list, long long int);
	else if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "z"))
		value = va_arg(list, size_t);
	else
		value = va_arg(list, int);
	if (value < 0)
	{
		value = -value;
		(*spec_f)->its_value_negative = 1;
	}
	(*spec_f)->value = ft_lltoa(value);
}

void	va_arg_unsgnt_int(t_flag **spec_f, va_list list)
{
	ULLI	value;

	if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "hh"))
		value = (unsigned char)va_arg(list, int);
	else if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "h"))
		value = (unsigned short int)va_arg(list, int);
	else if ((*spec_f)->its_size && (!ft_strcmp((*spec_f)->its_size, "l") ||
	!ft_strcmp((*spec_f)->its_size, "ll") ||
	!ft_strcmp((*spec_f)->its_size, "j")))
		value = va_arg(list, ULLI);
	else if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "z"))
		value = va_arg(list, size_t);
	else
		value = va_arg(list, unsigned int);
	(*spec_f)->value = ft_ulltoa_base(value, 10);
}

void	va_arg_pointer(t_flag **spec_f, va_list list)
{
	size_t				i;
	unsigned long int	value;
	char				*cvalue;
	char				*result;

	i = sizeof(unsigned long int) * 2;
	cvalue = ft_strnew(i);
	(*spec_f)->its_value_negative = 0;
	value = (unsigned long int)va_arg(list, void*);
	if (value > 0)
	{
		while (i-- > 0 && value > 0)
		{
			cvalue[i] = "0123456789abcdef"[value & 0x0F];
			value >>= 4;
		}
		result = ft_strnew(sizeof(unsigned long int) * 2 - i + 1);
		result = ft_strcat(result, cvalue + i + 1);
		free(cvalue);
		(*spec_f)->value = result;
	}
	else
		(*spec_f)->value = ft_strncpy(cvalue, "0", 1);
}

void	va_arg_char(t_flag **spec_f, va_list list)
{
	char	*ptr;
	char	value;

	if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "l"))
		va_arg_wchar_t(&(*spec_f), list);
	else
	{
		ptr = ft_strnew(1);
		value = va_arg(list, int);
		(*spec_f)->value = ft_strncpy(ptr, &value, 1);
	}
}

void	va_arg_string(t_flag **spec_f, va_list list)
{
	char	*ptr;

	if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "l"))
		va_arg_sup(&(*spec_f), list);
	else
	{
		if (!(ptr = va_arg(list, char*)))
		{
			(*spec_f)->value = ft_strnew(8);
			(*spec_f)->value = ft_strcat((*spec_f)->value, "(null)");
		}
		else
		{
			(*spec_f)->value = ft_strnew(ft_strlen(ptr));
			(*spec_f)->value = ft_strcat((*spec_f)->value, ptr);
		}
	}
}
