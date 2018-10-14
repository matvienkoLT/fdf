/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:53:58 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/06 15:35:04 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define UN	unsigned int

static UN	ft_ck_ng_value(int num, int *minus)
{
	UN	va;

	if (num < 0)
	{
		va = -num;
		*minus = 1;
		return (va);
	}
	else
		return ((UN)num);
}

static int	ft_dgt_quntt(UN n, UN base)
{
	int	quantt;

	if (n == 0)
		return (1);
	quantt = 0;
	while (n > 0)
	{
		n /= base;
		quantt++;
	}
	return (quantt);
}

static char	*ft_cr_string(int *m, size_t size, UN n, UN base)
{
	int		index;
	int		pre_state;
	char	*s;

	if (!(s = ft_strnew(sizeof(char) * size)))
		return (NULL);
	index = size;
	if (*m)
		s[0] = '-';
	else if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		if ((pre_state = n % base) > 9)
			s[--index] = pre_state + 87;
		else
			s[--index] = pre_state + '0';
		n /= base;
	}
	return (s);
}

char		*ft_itoa_base(int n, UN base)
{
	char			*ptr_n;
	int				minus;
	size_t			size;
	UN				value;

	minus = 0;
	value = ft_ck_ng_value(n, &minus);
	size = ft_dgt_quntt(value, base) + minus;
	ptr_n = ft_cr_string(&minus, size, value, base);
	return (ptr_n);
}
