/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afect_flags_pthird.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 10:32:09 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/26 11:34:46 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define LLI long long int

static char	*g_flag_precision = "diouxX";

void	ft_affect_float(t_flag *box)
{
	if (box->its_float && (box->type == 'F' || box->type == 'f'))
		box->value = ft_ftoa(box->float_val, box->precision);
	else if (box->its_float && (box->type == 'E' || box->type == 'e'))
		(box)->value = ft_scientific_format(&box);
	else if (box->its_float && (box->type == 'g' || box->type == 'G'))
		(box)->value = ft_short_float_format(&box);
	box->len_v = ft_strlen((box)->value);
}

void	ft_affect_width_float(t_flag *box, int *sym)
{
	LLI	tt;

	if (box->its_float && box->its_minus == 0)
	{
		tt = (LLI)box->len_v;
		tt = (LLI)box->its_width - tt;
		tt -= box->its_plus;
		while (tt-- > 0)
		{
			write(1, " ", 1);
			(*sym)++;
		}
		if (box->its_space && !box->its_value_negative)
		{
			write(1, " ", 1);
			(*sym)++;
		}
	}
}

void	ft_affect_hash(t_flag *box, int *sym)
{
	if (box->its_hash)
	{
		if ((box->type == 'o' || box->type == 'O') &&
			box->precision <= box->len_v)
		{
			(*sym)++;
			write(1, "0", 1);
		}
		else if (box->type == 'x' && (ft_strcmp(box->value, "0") != 0))
		{
			(*sym) += 2;
			write(1, "0x", 2);
		}
		else if (box->type == 'X' && (ft_strcmp(box->value, "0") != 0))
		{
			(*sym) += 2;
			write(1, "0X", 2);
		}
	}
}

void	ft_affect_plus(t_flag *box, int *sym)
{
	if (box->type != 's' && box->type != 'u' && box->type != 'o' &&
		box->type != 'S' && box->type != 'U' && box->type != 'O' &&
		box->type != 'c' && box->type != 'C' && box->type != 'x' &&
		box->type != 'X' && box->type != 'p')
	{
		if (box->its_value_negative == 1 && !box->its_float)
		{
			write(1, "-", 1);
			(*sym)++;
		}
		else if (box->its_value_negative == 0 && box->its_plus)
		{
			(*sym)++;
			write(1, "+", 1);
		}
	}
}

void	ft_corr_tools_type(t_flag *box, LLI *len)
{
	if (box->type == 'p')
		*len += 2;
	else if (check_affect_for_type(&box->type, g_flag_precision) &&
		box->its_dot && !ft_strcmp(box->value, "0"))
		*len = 0;
	else if (box->type == 'c' && *box->value == '\0')
		*len += 1;
	else if (box->its_hash && (box->type == 'x' ||
box->type == 'X') && (*(box->value) != '0'))
		*len += 2;
	else if (box->its_hash && box->type == 'o' &&
		(*(box->value) != '0'))
		*len += 1;
}
