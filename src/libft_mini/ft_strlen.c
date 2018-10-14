/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:52:28 by lmatvien          #+#    #+#             */
/*   Updated: 2018/04/05 12:02:36 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;
	int		switcher;

	if (str == NULL)
		return (0);
	i = 0;
	switcher = 0;
	while (switcher == 0)
	{
		if (str[i] == '\0')
		{
			switcher = 1;
			continue;
		}
		i++;
	}
	return (i);
}
