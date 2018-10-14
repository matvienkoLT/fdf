/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroyer_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:55:26 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/16 12:44:33 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		free_memory(t_flag *box, char *specifiers, int *sym)
{
	if (box->value)
		free(box->value);
	if (specifiers)
		free(specifiers);
	return (*sym);
}

void	ft_wcstr_negativ_signed(char *ptr, t_flag **box)
{
	char	*p;

	free(ptr);
	p = ft_strnew(2);
	*p = -1;
	(*box)->value = p;
}
