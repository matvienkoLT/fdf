/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_converter_psecond.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:03:49 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/14 15:22:41 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ULLI unsigned long long int

void	va_arg_octal(t_flag **spec_f, va_list list)
{
	ULLI	value;

	if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "hh"))
		value = (unsigned char)va_arg(list, int);
	else if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "h"))
		value = (unsigned short int)va_arg(list, int);
	else if (((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "l")) ||
		((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "ll")) ||
		((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "j")))
		value = va_arg(list, ULLI);
	else if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "z"))
		value = va_arg(list, size_t);
	else
		value = va_arg(list, unsigned int);
	(*spec_f)->value = ft_ulltoa_base(value, 8);
}

void	va_arg_hexa(t_flag **spec_f, va_list list)
{
	ULLI	value;

	if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "hh"))
		value = (unsigned char)va_arg(list, int);
	else if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "h"))
		value = (unsigned short int)va_arg(list, int);
	else if (((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "l")) ||
		((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "ll")) ||
		((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "j")))
		value = va_arg(list, ULLI);
	else if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "z"))
		value = va_arg(list, size_t);
	else
		value = va_arg(list, unsigned int);
	(*spec_f)->value = ft_ulltoa_base(value, 16);
}

void	va_arg_hexaup(t_flag **spec_f, va_list list)
{
	char	*ptr;

	va_arg_hexa(&(*spec_f), list);
	ptr = (*spec_f)->value;
	while (*ptr != '\0')
	{
		if (*ptr >= 97 && *ptr <= 122)
			*ptr -= 32;
		ptr++;
	}
}

void	va_arg_float(t_flag **spec_f, va_list list)
{
	(*spec_f)->its_float = 1;
	if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "L"))
		(*spec_f)->float_val = va_arg(list, long double);
	else
		(*spec_f)->float_val = va_arg(list, double);
	if ((*spec_f)->float_val < 0)
		(*spec_f)->its_value_negative = 1;
	ft_settings_float(&(*spec_f));
}

void	va_arg_floatup(t_flag **spec_f, va_list list)
{
	(*spec_f)->its_float = 1;
	if ((*spec_f)->its_size && !ft_strcmp((*spec_f)->its_size, "L"))
		(*spec_f)->float_val = va_arg(list, long double);
	else
		(*spec_f)->float_val = va_arg(list, double);
	if ((*spec_f)->float_val < 0)
		(*spec_f)->its_value_negative = 1;
	ft_settings_float(&(*spec_f));
}
