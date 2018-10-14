/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:02:22 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/10 09:47:23 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

t_pixel_pack	*create_pack(void)
{
	t_pixel_pack	*p_lst;

	if (!(p_lst = (t_pixel_pack*)malloc(sizeof(t_pixel_pack))))
		return (NULL);
	else
	{
		p_lst->z = 0;
		p_lst->written = 0;
		p_lst->n_node = NULL;
		p_lst->h_node = NULL;
		p_lst->rgb_color = 0xFFFFFF;
	}
	return (p_lst);
}

static void		ft_push_back(t_pixel_pack **lst)
{
	if ((*lst = (t_pixel_pack*)malloc(sizeof(t_pixel_pack))))
	{
		(*lst)->z = 0;
		(*lst)->written = 0;
		(*lst)->n_node = NULL;
		(*lst)->h_node = NULL;
		(*lst)->rgb_color = 0xFFFFFF;
	}
	else
		lst = NULL;
}

static void		fillit_h_node(t_pixel_pack **h_node, t_pixel_pack *p_save)
{
	p_save->h_node = *h_node;
	*h_node = (*h_node)->n_node;
}

void			list_fillit(char **str, t_pixel_pack **pack, t_p_fillit *p_pck)
{
	char	**s_str;
	int		i;

	i = 0;
	s_str = str;
	if (!(p_pck->p_begin))
	{
		p_pck->p_begin = create_pack();
		p_pck->p_save_position = p_pck->p_begin;
	}
	while (s_str[i])
	{
		if (p_pck->p_save_position->written)
		{
			ft_push_back(&(p_pck->p_save_position->n_node));
			p_pck->p_save_position = p_pck->p_save_position->n_node;
		}
		if (!(z_cord_finder(s_str[i], p_pck, i)))
			ssymb_error(str);
		if (p_pck->p_high_elem)
			fillit_h_node(&(p_pck->p_high_elem), p_pck->p_save_position);
		i++;
	}
}
