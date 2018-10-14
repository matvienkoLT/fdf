/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:15:14 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/21 10:09:47 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#define LLI long long int

static LLI	ft_ck_ng_value(LLI num, short int *minus)
{
	if (num < 0)
	{
		*minus = 1;
		return (-num);
	}
	else
		return (num);
}

static LLI	ft_dgt_quntt(LLI n)
{
	LLI	quantt;

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

static void	ft_cr_string(char *s, short int *m, size_t size, LLI n)
{
	LLI	index;

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

char		*ft_lltoa(LLI n)
{
	char			*ptr_n;
	short int		minus;
	size_t			size;
	LLI				value;

	minus = 0;
	if (n == LONG_MIN)
		return (ft_strcat(ft_strnew(21), "9223372036854775808"));
	value = ft_ck_ng_value(n, &minus);
	size = ft_dgt_quntt(value) + 1 + minus;
	ptr_n = (char *)malloc(sizeof(char) * size);
	if (!ptr_n)
		return (NULL);
	ft_cr_string(ptr_n, &minus, size, value);
	return (ptr_n);
}
