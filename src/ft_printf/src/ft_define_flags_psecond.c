/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_flags_psecond.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:33:53 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/28 11:31:24 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_dot(char *ptr, t_flag **spec_f)
{
	long long int	val;

	(*spec_f)->its_dot = 1;
	if (!(*spec_f)->its_star_s)
	{
		val = ft_atoi(ptr + 1);
		if (val < 0)
		{
			if ((*spec_f)->type == 'g' || (*spec_f)->type == 'G')
			{
				(*spec_f)->precision = 0;
				return (2);
			}
			val = -val;
		}
		(*spec_f)->precision = val;
	}
	return (2);
}

void	ft_check_star(char *ptr, va_list l, t_flag **spec_f)
{
	long long int	val;

	if (*(ptr - 1) == '.')
	{
		(*spec_f)->its_star_s = 1;
		(*spec_f)->precision = va_arg(l, int);
	}
	else
	{
		(*spec_f)->its_star_w = 1;
		val = va_arg(l, int);
		if (val < 0)
		{
			(*spec_f)->its_minus = 1;
			val = -val;
		}
		else if (val == 0)
			(*spec_f)->its_star_w = 0;
		(*spec_f)->its_width = val;
	}
}
