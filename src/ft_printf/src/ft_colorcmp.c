/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:00:33 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/28 13:57:25 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_colorcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char*)s2);
		s1++;
		s2++;
	}
	if (*s2 == '\0')
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char*)s2);
}
