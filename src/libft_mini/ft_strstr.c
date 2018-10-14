/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:03:14 by lmatvien          #+#    #+#             */
/*   Updated: 2018/03/28 16:24:21 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*result;
	const char	*ptr_result;
	const char	*ptr_needle;

	if (*needle == '\0')
		return ((char *)haystack);
	ptr_needle = needle;
	result = ft_strchr(haystack, *needle);
	if (result == NULL)
		return (NULL);
	else
	{
		ptr_result = result;
		while (*(++ptr_needle) != '\0')
		{
			if (*(++ptr_result) != *ptr_needle)
			{
				result = ft_strstr(++result, needle);
				break ;
			}
		}
	}
	return ((char *)result);
}
