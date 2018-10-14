/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:03:01 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/01 11:27:45 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ftoa.h"

LLI		ft_degree(int val, int cnt)
{
	long long int res;

	res = 1;
	while (cnt-- > 0)
		res *= val;
	return (res);
}

LLI		ft_fpow(LD v, size_t deg, LD p)
{
	if (deg > 0)
		return (ft_fpow(v * p, --deg, p));
	else if (v - (int)v >= 0.5 && (int)v > 0)
		return (v + 1);
	else
		return (v);
}

LD		ft_precision(size_t pre)
{
	LD	p;

	p = (LD)0.1;
	while (pre-- > 0)
		p *= 0.1;
	p += (LD)10;
	return (p);
}

char	*ft_negative_zero(char *bis_part)
{
	char	*ptr;

	ptr = ft_strnew(2);
	*ptr = '-';
	*(ptr + 1) = '0';
	free(bis_part);
	return (ptr);
}

LLI		ft_z_ch(LD n_t, size_t p)
{
	LLI	zero;
	LLI	count;

	count = 0;
	zero = (n_t * 10);
	while (zero == 0 && p > 1)
	{
		zero = ft_fpow(n_t, count + 2, 10.000);
		count++;
		p--;
	}
	return (count);
}
