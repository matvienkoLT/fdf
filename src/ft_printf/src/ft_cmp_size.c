/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:12:58 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/28 11:32:11 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_incorrect_spec(char **f, char **fo, char **ptr, t_flag *list)
{
	list->type = -1;
	*fo = ft_strnew((size_t)(*ptr - *f + 1));
	list->value = ft_strncpy(ft_strnew(1), *ptr, 1);
}

int		ft_cmp_size(char *ptr_to_char, char *size)
{
	char	*ptr;

	ptr = (char *)g_all_size;
	if ((*ptr_to_char == 'h' && *(ptr_to_char + 1) == 'h') ||
		(*ptr_to_char == 'l' && *(ptr_to_char + 1) == 'l'))
	{
		ft_strncpy(size, ptr_to_char, 2);
		size[2] = '\0';
		return (2);
	}
	while (*ptr != '\0')
	{
		if (*ptr_to_char == *ptr)
		{
			size[0] = *ptr;
			size[1] = '\0';
			return (1);
		}
		ptr++;
	}
	return (0);
}
