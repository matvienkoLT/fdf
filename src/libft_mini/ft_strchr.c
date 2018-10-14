/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:54:40 by lmatvien          #+#    #+#             */
/*   Updated: 2018/04/04 18:12:49 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if ((unsigned char)c == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
		{
			return ((char *)str);
		}
		++str;
	}
	return (NULL);
}
