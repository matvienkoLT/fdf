/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_converter_psix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:32:27 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/01 17:38:05 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dgt_quntt(long long int n)
{
	int	quantt;

	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	quantt = 0;
	while (n > 0)
	{
		n /= 10;
		quantt++;
	}
	return (quantt);
}

static char	*ft_not_enough_precision(t_flag **spec_f)
{
	long long int temp;

	temp = (*spec_f)->float_val;
	if ((*spec_f)->float_val - temp >= 0.5)
		temp += 1.0;
	(*spec_f)->type = 'd';
	return (ft_lltoa(temp));
}

char		*ft_short_float_format(t_flag **spec_f)
{
	int len;

	len = ft_dgt_quntt((*spec_f)->float_val);
	if ((size_t)len == (*spec_f)->precision)
		return (ft_not_enough_precision(&(*spec_f)));
	else if ((*spec_f)->precision < (size_t)len && (*spec_f)->its_dot)
	{
		if ((*spec_f)->precision > 0)
			(*spec_f)->precision -= 1;
		(*spec_f)->its_scientific_f = 1;
		return (ft_scientific_format(&(*spec_f)));
	}
	if ((long long int)(*spec_f)->float_val == 0)
		len = (*spec_f)->precision;
	else if ((*spec_f)->precision > (size_t)len)
		len = (*spec_f)->precision - len;
	if ((*spec_f)->its_dot && !(*spec_f)->precision)
	{
		len = 1;
		(*spec_f)->its_scientific_f = 1;
		return (ft_scientific_format(&(*spec_f)));
	}
	return (ft_ftoa_scast((*spec_f)->float_val, len));
}

void		arg_count(t_flag **spec_f, va_list list)
{
	(void)list;
	(*spec_f)->value = ft_strnew(1);
	(*spec_f)->address = va_arg(list, int*);
}
