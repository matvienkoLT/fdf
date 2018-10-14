/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_destroyer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:55:19 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/08 20:36:10 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	lst_cleaner(t_pixel_pack **pack)
{
	t_pixel_pack	*p_position;
	t_pixel_pack	*p_del;

	p_position = *pack;
	while (p_position->n_node)
	{
		p_del = p_position->n_node;
		free(p_position);
		p_position = p_del;
	}
	free(p_position);
}

void	tab_cleaner(char **tab)
{
	char **ls;

	ls = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(ls);
}
