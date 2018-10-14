/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:34:17 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/31 17:59:37 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int		ft_ck_ng_value(int num, int *minus)
{
	unsigned int	va;

	if (num < 0)
	{
		va = -num;
		*minus = 1;
		return (va);
	}
	else
		return ((unsigned int)num);
}

static int				ft_dgt_quntt(unsigned int n)
{
	int	quantt;

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

static void				ft_cr_string(char *s, int *m, int size, unsigned int n)
{
	int	index;

	index = size - 1;
	if (*m)
		s[0] = '-';
	else if (n == 0)
		s[0] = '0';
	s[index] = '\0';
	while (n > 0)
	{
		s[--index] = n % 10 + '0';
		n /= 10;
	}
}

char					*ft_itoa(int n)
{
	char			*ptr_n;
	int				minus;
	size_t			size;
	unsigned int	value;

	minus = 0;
	value = ft_ck_ng_value(n, &minus);
	size = ft_dgt_quntt(value) + 1 + minus;
	ptr_n = (char *)malloc(sizeof(char) * size);
	if (!ptr_n)
		return (NULL);
	ft_cr_string(ptr_n, &minus, size, value);
	return (ptr_n);
}
