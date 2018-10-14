/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:52:40 by lmatvien          #+#    #+#             */
/*   Updated: 2018/03/28 16:22:48 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str, const char *source, size_t num)
{
	char	*destination;

	if (*source != '\0' || source)
	{
		destination = str;
		while (*destination != '\0')
			destination++;
		while (*source != '\0' && num > 0)
		{
			*destination = *source;
			source++;
			destination++;
			num--;
		}
		*destination = '\0';
	}
	return (str);
}
