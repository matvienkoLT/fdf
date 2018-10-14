/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:16:48 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/14 12:11:04 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define UN	unsigned int
#define ULLI unsigned long long int

static size_t	ft_dgt_quntt(ULLI n, UN base)
{
	size_t	quantt;

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

static char		*ft_cr_string(size_t size, ULLI n, UN base)
{
	size_t		index;
	int			pre_state;
	char		*s;

	if (!(s = ft_strnew(sizeof(char) * size)))
		return (NULL);
	index = size;
	if (n == 0)
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

char			*ft_ulltoa_base(ULLI value, UN base)
{
	char			*ptr_n;
	size_t			size;

	size = ft_dgt_quntt(value, base);
	ptr_n = ft_cr_string(size, value, base);
	return (ptr_n);
}
