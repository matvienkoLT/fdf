/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:28:10 by lmatvien          #+#    #+#             */
/*   Updated: 2018/04/02 16:06:47 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr_dest;
	size_t	i;

	if (n == 0)
		return (str);
	i = 0;
	ptr_dest = (char *)str;
	while (i < n)
	{
		ptr_dest[i] = c;
		i++;
	}
	return (ptr_dest);
}
