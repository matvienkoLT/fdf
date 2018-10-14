/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:35:27 by lmatvien          #+#    #+#             */
/*   Updated: 2018/04/04 18:13:57 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr_str;

	ptr_str = NULL;
	if ((unsigned char)c == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	while (*str)
	{
		if (*str == (unsigned char)c)
			ptr_str = (char *)str;
		++str;
	}
	return (ptr_str);
}
