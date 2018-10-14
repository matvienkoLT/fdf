/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 12:26:13 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/18 17:08:40 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define D_MAX_INT 0x7FFFFFFF

static int		ft_pow(int base, size_t z)
{
	int value;

	if (z == 0)
		value = 1;
	else
		(value = base);
	while (z-- > 1)
		value *= base;
	return (value);
}

static int		minus_decimal(char *str, int base)
{
	int minus;

	minus = 1;
	if (base == 10 && *str == '-')
		minus = -1;
	return (minus);
}

static int		check_base(char *str, int *base, size_t *size, long long int *v)
{
	int status;

	status = 1;
	if ((*base > (*str - 55) && *str <= 126) || (*str >= 97 && *str <= 122))
	{
		if (*str <= 57)
			*v += ft_pow(*base, *size) * (*str - '0');
		else if (*str >= 97 && *str <= 122)
			*v += ft_pow(*base, *size) * (*str - 87);
		else
			*v += ft_pow(*base, *size) * (*str - 55);
		(*size)--;
	}
	else
		status = 0;
	return (status);
}

int				ft_atoi_base(char *str, int base)
{
	long long int	value;
	size_t			size;
	int				minus;

	value = 0;
	minus = minus_decimal(str, base);
	size = ft_strlen(str) - 1;
	while (*str != '\0')
	{
		if (!check_base(str, &base, &size, &value))
			return (0);
		if (value > D_MAX_INT)
			return (0);
		str++;
	}
	return (value * minus);
}
