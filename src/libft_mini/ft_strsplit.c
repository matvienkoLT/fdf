/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:45:22 by lmatvien          #+#    #+#             */
/*   Updated: 2018/04/02 15:41:51 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char *c)
{
	size_t	qntt;
	size_t	itr;

	qntt = 0;
	itr = 0;
	while (str[itr] != '\0')
	{
		if (str[itr] != *c)
		{
			qntt++;
			while (str[itr] != *c && str[itr] != '\0')
				itr++;
		}
		else
			itr++;
	}
	return (qntt);
}

static char		*overlook_sprtr(char *str, char *c)
{
	while (*str == *c && *str != '\0')
		str++;
	return (str);
}

static size_t	len_word(char const *str, char *c)
{
	size_t	qntt;

	qntt = 0;
	while (*str != *c && *str++ != '\0')
		qntt++;
	return (qntt);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new_array;
	char	*ptr_s;
	size_t	qw;
	size_t	qc;
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	ptr_s = (char *)s;
	qw = count_words(s, &c);
	new_array = (char **)malloc(sizeof(char *) * (qw + 1));
	if (!new_array)
		return (NULL);
	while (i < qw)
	{
		ptr_s = overlook_sprtr(ptr_s, &c);
		qc = len_word(ptr_s, &c);
		new_array[i] = ft_strnew(qc);
		ft_strncpy(new_array[i], ptr_s, qc);
		ptr_s += qc;
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}
