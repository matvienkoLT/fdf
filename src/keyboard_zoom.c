/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_zoom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:32:58 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/16 11:51:59 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

#define Z pack->box->zoom
#define BOX pack->box
#define SZ pack->sz[1]

static int	verify_zoom(t_imgr *pack)
{
	int		uxtep;
	int		ystep;
	float	new_point;
	float	status;
	int		tep;

	status = 1;
	tep = (SZ - (BOX->z_max * Z - BOX->z_min * Z) / 2) / 5;
	uxtep = SZ / (BOX->step * BOX->rows) * Z;
	new_point = (BOX->max_y - tep - BOX->move_y) / uxtep;
	ystep = SZ / (BOX->step * BOX->rows) * (Z + 1);
	new_point *= ystep;
	tep = (SZ - (BOX->z_max * (Z + 1) - BOX->z_min * (Z + 1)) / 2) / 5;
	new_point += tep + BOX->move_y;
	if (new_point > (SZ - 10) || (BOX->min_y - (ystep - uxtep) < 10))
		status = 0;
	return (status);
}

void		keyboard_zooming(int key, t_imgr *pack)
{
	if (key == 67 && verify_zoom(pack))
	{
		pack->box->zoom += 1;
		if (!render(pack))
		{
			pack->box->zoom -= 1;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	if (key == 75 && pack->box->zoom - 1 >= 1)
	{
		pack->box->zoom -= 1;
		if (!render(pack))
		{
			pack->box->zoom += 1;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
}
