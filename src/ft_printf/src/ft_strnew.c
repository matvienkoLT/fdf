/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:51:53 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/13 12:28:46 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*ptr_str;

	if (!(ptr_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (ft_memset(ptr_str, '\0', size + 1));
}
