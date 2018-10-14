/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primary_setting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 10:37:15 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/01 16:37:36 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_num_digit(long long int n)
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

void	ft_settings_float(t_flag **box)
{
	if ((*box)->its_value_negative && ((*box)->type == 'e' ||
	(*box)->type == 'E'))
		(*box)->float_val *= (-1);
	(*box)->precision = 6;
}
