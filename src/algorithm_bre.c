/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_bre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:58:21 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/11 13:44:59 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

#define X0 block->x_mod
#define Y0 block->y_mod
#define X1 block->n_node->x_mod
#define Y1 block->n_node->y_mod

static int	check_direction_x(int x0, int x1)
{
	int dx;

	if (x1 > x0)
		dx = x1 - x0;
	else
		dx = x0 - x1;
	return (dx);
}

static int	check_direction_y(int y0, int y1)
{
	int dy;

	if (y1 > y0)
		dy = y1 - y0;
	else
		dy = y0 - y1;
	return (dy);
}

static void	dy_direction(t_cord_bre *krd, t_pixel_pack *block, int *sz, int *im)
{
	int i;

	i = 0;
	krd->err = (krd->dx << 1) - krd->dy;
	krd->ystep = (krd->dx - krd->dy) << 1;
	krd->y = Y0 + krd->sy;
	krd->x = X0;
	filling_color(&im[krd->x + sz[0] * krd->y], block);
	while (i <= krd->dy)
	{
		if (krd->err < 0)
			krd->err += krd->dx << 1;
		else
		{
			krd->x += krd->sx;
			krd->err += krd->ystep;
		}
		filling_color(&im[krd->x + sz[0] * FT_ABS(krd->y)], block);
		krd->y += krd->sy;
		i++;
	}
}

static void	dx_direction(t_cord_bre *krd, t_pixel_pack *block, int *sz, int *im)
{
	int i;

	i = 0;
	krd->err = (krd->dy << 1) - krd->dx;
	krd->ystep = (krd->dy - krd->dx) << 1;
	krd->y = Y0;
	krd->x = X0 + krd->sx;
	filling_color(&im[krd->x + sz[0] * krd->y], block);
	while (i <= krd->dx)
	{
		if (krd->err < 0)
			krd->err += (krd->dy << 1);
		else
		{
			krd->y += krd->sy;
			krd->err += krd->ystep;
		}
		filling_color(&im[krd->x + sz[0] * krd->y], block);
		krd->x += krd->sx;
		i++;
	}
}

void		algorithm_bre(t_pixel_pack *block, int *im, int *sz)
{
	t_cord_bre krd;

	krd.dx = check_direction_x(X0, X1);
	krd.dy = check_direction_y(Y0, Y1);
	if (X1 >= X0)
		krd.sx = 1;
	else
		krd.sx = -1;
	if (Y1 >= Y0)
		krd.sy = 1;
	else
		krd.sy = -1;
	if (krd.dx > krd.dy)
		dx_direction(&krd, block, sz, im);
	else
		dy_direction(&krd, block, sz, im);
}
