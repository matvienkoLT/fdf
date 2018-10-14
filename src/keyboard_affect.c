/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_affect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:00:00 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/18 16:29:33 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	pushed_key_5(int key, t_imgr *pack)
{
	if (key == 82)
	{
		pack->box->swerve = 0.0;
		pack->box->move_x = 1;
		pack->box->move_y = 1;
		pack->box->angle_x = 1;
		pack->box->angle_y = 0;
		pack->box->z_v = 1;
		pack->box->zoom = 1;
		pack->box->gradient = 0;
		if (!render(pack))
			control_error(pack->box->p_begin);
	}
	else if (key == 71)
	{
		if (!pack->box->gradient)
			pack->box->gradient = 1;
		else
			pack->box->gradient = 0;
		render(pack);
	}
	else
		pushed_key_p(key, pack);
}

static void	pushed_key_4(int key, t_imgr *pack)
{
	if (key == 78)
	{
		pack->box->z_v -= 3;
		if (!render(pack))
		{
			pack->box->z_v += 3;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	else if (key == 75 || key == 67)
		keyboard_zooming(key, pack);
	else
		pushed_key_5(key, pack);
}

static void	pushed_key_3(int key, t_imgr *pack)
{
	if (key == 126)
	{
		pack->box->move_y -= 5;
		if (!render(pack))
		{
			pack->box->move_y += 5;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	else if (key == 69)
	{
		pack->box->z_v += 3;
		if (!render(pack))
		{
			pack->box->z_v -= 3;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	else
		pushed_key_4(key, pack);
}

static void	pushed_key_2(int key, t_imgr *pack)
{
	if (key == 123)
	{
		pack->box->move_x -= 5;
		if (!render(pack))
		{
			pack->box->move_x += 5;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	if (key == 125)
	{
		pack->box->move_y += 5;
		if (!render(pack))
		{
			pack->box->move_y -= 5;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	else
		pushed_key_3(key, pack);
}

int			pushed_key(int key, t_imgr *pack)
{
	if (key == 53)
	{
		ft_printf("{red}{bold}{unline}Exit. See you soon!{eoc}\n");
		lst_cleaner(&pack->box->p_begin);
		exit(0);
	}
	if (key == 124)
	{
		pack->box->move_x += 5;
		if (!render(pack))
		{
			pack->box->move_x -= 5;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	else
		pushed_key_2(key, pack);
	return (1);
}
