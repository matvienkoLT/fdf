/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imager.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:08:45 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/18 16:26:35 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

#define NAV_LIST lst->CUR_POS->x_mod
#define NAV_LST_NDX lst->CUR_POS->n_node->x
#define Z lst->zoom

static void		imager_v(char *im, t_p_fillit *lst, int *sz)
{
	lst->CUR_POS = lst->BEG_POS;
	while (!lst->CUR_POS->h_node)
		lst->CUR_POS = lst->CUR_POS->n_node;
	while (lst->CUR_POS)
	{
		algorithm_bre_v(lst->CUR_POS, (int *)im, sz, &lst->gradient);
		lst->CUR_POS = lst->CUR_POS->n_node;
	}
}

static void		new_line(t_p_fillit *lst, int *i, int *j)
{
	*i = *j;
	lst->CUR_POS = lst->CUR_POS->n_node;
	lst->CUR_POS->y_mod += (lst->angle_y * (*j));
	lst->CUR_POS->x_mod += (lst->angle_x * (*j));
	if (lst->CUR_POS->y_mod > lst->max_y)
		lst->max_y = lst->CUR_POS->y_mod;
	if (lst->CUR_POS->y_mod < lst->min_y)
		lst->min_y = lst->CUR_POS->y_mod;
	(*j)++;
}

static void		imager(char *im, t_p_fillit *lst, int *sz)
{
	int i;
	int j;

	i = 1;
	j = 1;
	lst->CUR_POS = lst->BEG_POS;
	while (lst->CUR_POS->n_node)
	{
		if (lst->CUR_POS->x != lst->width - 1)
		{
			lst->CUR_POS->n_node->y_mod += (lst->angle_y * i);
			lst->CUR_POS->n_node->x_mod += (lst->angle_x * i);
			if (lst->CUR_POS->y_mod > lst->max_y)
				lst->max_y = lst->CUR_POS->y_mod;
			if (lst->CUR_POS->y_mod < lst->min_y)
				lst->min_y = lst->CUR_POS->y_mod;
			algorithm_bre(lst->CUR_POS, (int *)im, sz);
			lst->CUR_POS = lst->CUR_POS->n_node;
		}
		else
			new_line(lst, &i, &j);
		i++;
	}
}

static void		determine_step(int *sz, int *step, int *uxtep, t_p_fillit *lst)
{
	*step = sz[1] / (lst->step * lst->rows) * Z;
	*uxtep = (sz[1] - (lst->z_max * Z - lst->z_min * Z) / 2) / 4;
	lst->min_y = lst->CUR_POS->y * (*step) + (*uxtep) + lst->move_y;
	lst->max_y = 0;
	lst->min_x = lst->CUR_POS->x * (*step) + (*uxtep) + lst->move_x + 50;
	lst->max_x = 0;
}

int				zoom_setting(char *im, t_p_fillit *lst, int *sz)
{
	int step;
	int uxtep;

	lst->step = 10;
	if (lst->rows > 100)
		lst->step = 2;
	lst->CUR_POS = lst->BEG_POS;
	determine_step(sz, &step, &uxtep, lst);
	while (lst->CUR_POS)
	{
		lst->CUR_POS->x_mod = lst->CUR_POS->x * step + lst->move_x + 50;
		lst->CUR_POS->y_mod = lst->CUR_POS->y * step + uxtep +
			lst->move_y - lst->CUR_POS->z * lst->z_v;
		if (!(ch_cord_pos(lst, lst->CUR_POS, sz)))
			return (0);
		lst->CUR_POS = lst->CUR_POS->n_node;
	}
	if (!(check_rotate(lst, sz)))
		return (0);
	imager(im, lst, sz);
	imager_v(im, lst, sz);
	return (1);
}
