/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:04:18 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/18 16:31:05 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	pushed_key_7(int key, t_imgr *pack)
{
	float preserve;

	if (key == 83)
	{
		pack->box->angle_x -= 1;
		if (!render(pack))
		{
			pack->box->angle_x += 1;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
}

static void	pushed_key_6(int key, t_imgr *pack)
{
	float preserve;

	if (key == 84)
	{
		pack->box->angle_x += 1;
		if (!render(pack))
		{
			pack->box->angle_x -= 1;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	if (key == 71)
	{
		preserve = pack->box->swerve;
		pack->box->swerve = 0.0;
		if (!render(pack))
		{
			pack->box->swerve = preserve;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	else
		pushed_key_7(key, pack);
}

void		pushed_key_p(int key, t_imgr *pack)
{
	float preserve;

	if (key == 92)
	{
		pack->box->swerve += 0.174;
		if (!render(pack))
		{
			pack->box->swerve -= 0.174;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	if (key == 89)
	{
		preserve = pack->box->swerve;
		pack->box->swerve = 0.0;
		if (!render(pack))
		{
			pack->box->swerve = preserve;
			if (!render(pack))
				control_error(pack->box->p_begin);
		}
	}
	else
		pushed_key_6(key, pack);
}
