/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_converter_pfour.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:49:09 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/16 12:42:51 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	va_arg_dup(t_flag **spec_f, va_list list)
{
	long long int	value;

	value = va_arg(list, long long int);
	if (value < 0)
	{
		value = -value;
		(*spec_f)->its_value_negative = 1;
	}
	(*spec_f)->value = ft_lltoa(value);
}

void	va_arg_uup(t_flag **spec_f, va_list list)
{
	long long int	value;

	value = va_arg(list, long long int);
	(*spec_f)->value = ft_ulltoa_base(value, 10);
}

void	va_arg_oup(t_flag **spec_f, va_list list)
{
	unsigned long long int value;

	value = va_arg(list, unsigned long long int);
	(*spec_f)->value = ft_ulltoa_base(value, 8);
}

void	va_arg_sup(t_flag **spec_f, va_list list)
{
	wchar_t	*format;
	char	*ptr;

	if (!(format = va_arg(list, wchar_t*)))
	{
		(*spec_f)->value = ft_strnew(8);
		(*spec_f)->value = ft_strcat((*spec_f)->value, "(null)");
	}
	else
	{
		ptr = ft_strnew(ft_wcstrlen(format) * 4);
		while (*format != '\0')
		{
			if (*format < 0)
				return (ft_wcstr_negativ_signed(ptr, spec_f));
			str_wchar(*format, &(*spec_f));
			ptr = ft_strcat(ptr, (*spec_f)->value);
			free((*spec_f)->value);
			format++;
		}
		(*spec_f)->value = ptr;
	}
}

void	arg_percent(t_flag **spec_f, va_list list)
{
	(void)list;
	(*spec_f)->value = ft_strnew(1);
	*((*spec_f)->value) = '%';
}
