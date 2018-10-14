/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pctr_rtt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:57:34 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/18 21:00:15 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"
#include "math.h"

#define X_MOD tk->x_mod
#define Y_MOD tk->y_mod
#define LC lst->swerve

int			ch_cord_pos(t_p_fillit *lst, t_pixel_pack *pack, int *sz)
{
	int status;

	status = 1;
	if (pack->y_mod > lst->max_y)
		lst->max_y = pack->y_mod;
	if (pack->y_mod < lst->min_y)
		lst->min_y = pack->y_mod;
	if (pack->x_mod > lst->max_x)
		lst->max_x = lst->CUR_POS->x_mod;
	if (pack->x_mod < lst->min_x)
		lst->min_x = pack->x_mod;
	if (lst->max_y > (sz[1] - 10) || lst->min_y < 10)
		status = 0;
	return (status);
}

static void	flatness_x(t_p_fillit *lst, t_pixel_pack *tk)
{
	int x_cent;
	int y_cent;
	int x_temp;
	int y_temp;

	x_cent = (lst->max_x + lst->min_x) / 2;
	y_cent = (lst->max_y + lst->min_y) / 2;
	x_temp = (x_cent + (X_MOD - x_cent) * cos(LC) - (Y_MOD - y_cent) * sin(LC));
	y_temp = (y_cent + (Y_MOD - y_cent) * cos(LC) + (X_MOD - x_cent) * sin(LC));
	X_MOD = x_temp;
	Y_MOD = y_temp;
}

static void	check_flatness_cor(int *min_y, int *max_y, t_pixel_pack *tk)
{
	if (Y_MOD > *max_y)
		*max_y = X_MOD;
	if (Y_MOD < *min_y)
		*min_y = Y_MOD;
}

int			check_rotate(t_p_fillit *lst, int *sz)
{
	int min_y;
	int max_y;
	int status;

	status = 1;
	max_y = lst->max_y;
	min_y = lst->min_y;
	if (lst->swerve > 0.0)
	{
		lst->CUR_POS = lst->BEG_POS;
		while (lst->CUR_POS)
		{
			flatness_x(lst, lst->CUR_POS);
			check_flatness_cor(&min_y, &max_y, lst->CUR_POS);
			lst->CUR_POS = lst->CUR_POS->n_node;
		}
		lst->max_y = max_y;
		lst->min_y = min_y;
		if (lst->max_y > sz[1] - 10 || lst->min_y < 10)
			status = 0;
	}
	return (status);
}
