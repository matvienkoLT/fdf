/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:27:29 by lmatvien          #+#    #+#             */
/*   Updated: 2018/03/29 12:48:15 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ptr_d;

	if (n || *src != '\0')
	{
		ptr_d = dest;
		while (*src != '\0' && n > 0)
		{
			*(ptr_d)++ = *(src++);
			n--;
		}
		while (n--)
			*ptr_d++ = '\0';
	}
	return (dest);
}
