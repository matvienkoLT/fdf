/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:51:49 by lmatvien          #+#    #+#             */
/*   Updated: 2018/03/28 15:11:13 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str, const char *source)
{
	char	*destination;

	destination = str;
	while (*destination != '\0')
		destination++;
	while (*source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
	return (str);
}
