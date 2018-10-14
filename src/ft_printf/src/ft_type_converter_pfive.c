/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_converter_pfive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:54:37 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/01 16:37:08 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define LD long double

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

static int	ft_exp_deg(LD val, LD *exp, int *mant, char **c)
{
	int degree;

	degree = 0;
	*c = "+0";
	if (val < 1.00000)
	{
		*c = "-0";
		while (val < 1.00000)
		{
			val *= 10;
			degree++;
		}
	}
	else if (val > 10.00000)
	{
		*c = "+0";
		while (val > 10.00000)
		{
			val /= 10;
			degree++;
		}
	}
	*mant = (int)val;
	*exp = val - *mant;
	return (degree);
}

char		*ft_scientific_format(t_flag **spec_f)
{
	char		*result;
	t_eformat	v;
	LD			per_dot;

	if ((*spec_f)->float_val < 0)
		(*spec_f)->float_val *= (-1);
	v.degree = ft_exp_deg((*spec_f)->float_val, &per_dot, &v.mant, &v.bhvr);
	v.per_dot = ft_ftoa(per_dot, (*spec_f)->precision);
	result = ft_strnew(ft_strlen(v.per_dot) + 4 + ft_dgt_quntt(v.degree));
	*v.per_dot = v.mant + '0';
	if ((*spec_f)->its_value_negative)
		*result = '-';
	result = ft_strcat(result, v.per_dot);
	if ((*spec_f)->type == 'E' || (*spec_f)->type == 'G')
		result = ft_strcat(result, "E");
	else
		result = ft_strcat(result, "e");
	result = ft_strcat(result, v.bhvr);
	v.bhvr = ft_itoa(v.degree);
	result = ft_strcat(result, v.bhvr);
	free(v.per_dot);
	free(v.bhvr);
	return (result);
}

void		va_arg_float_ef(t_flag **spec_f, va_list list)
{
	(*spec_f)->its_float = 1;
	(*spec_f)->float_val = va_arg(list, double);
	if ((*spec_f)->float_val < 0)
		(*spec_f)->its_value_negative = 1;
	ft_settings_float(&(*spec_f));
}
