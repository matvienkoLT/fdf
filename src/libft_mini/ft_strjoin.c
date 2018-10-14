/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:00:42 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/18 12:37:00 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const char	*ptr_s;
	size_t		size;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr_s = ft_strnew(size);
	if (!ptr_s)
		return (NULL);
	if (s1 != NULL)
		ft_strcpy((char *)ptr_s, (char *)s1);
	if (s2 != NULL)
		ft_strcat((char *)ptr_s, s2);
	return ((char *)ptr_s);
}
