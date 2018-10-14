/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 03:05:37 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/18 16:39:41 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

#define M_T mlx_get_data_addr

void	filling_color(int *color_bite, t_pixel_pack *block)
{
	color_bite[0] = block->rgb_color;
}

void	filling_grad_color(int *cb, t_pixel_pack *block, int *gr, int *i)
{
	int diff_color;

	if (*gr)
	{
		diff_color = *i * 0xffff;
		cb[0] = 0xffffff - diff_color;
		if (cb[0] <= 0)
			cb[0] = 0xff00ff;
	}
	else
		cb[0] = block->rgb_color;
}

int		render(t_imgr *pack)
{
	ft_memset(pack->tb->p_table, 0, pack->tb->size * pack->sz[1]);
	if (!zoom_setting(pack->tb->p_table, pack->box, &pack->sz[0]))
		return (0);
	mlx_put_image_to_window(pack->tb->p_mlx_win, pack->tb->p_win,
							pack->tb->p_img, 10, 25);
	return (1);
}
