/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:32:58 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/18 20:59:20 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

#define M_T mlx_get_data_addr

void		key_info(t_image_pack *wnd, int *sz)
{
	mlx_string_put(wnd->p_mlx_win, wnd->p_win, (sz[0] - sz[0]),
		2, 0x00bfff, "RESET ALL [0]  MOVE [ARROW BUTTON]  ROTATE [9]");
	mlx_string_put(wnd->p_mlx_win, wnd->p_win, (sz[0] + 460) - sz[0],
		2, 0x00bfff, "  ZOOM++ [*]-[/] ZOOM Z [+]-[-]");
}

static void	wnd_sz(t_p_fillit *pack, int *sz)
{
	if (pack->width <= 20)
		sz[0] = 860;
	else if (pack->width >= 100)
		sz[0] = 1400 + (pack->width * 0.75);
	else
		sz[0] = 1100 + (pack->width * 0.75);
	if (pack->rows <= 20)
		sz[1] = 760;
	else if (pack->width >= 100)
		sz[1] = 1100 + (pack->width * 0.75);
	else
		sz[1] = 900 + (pack->width * 0.75);
}

static void	zoom_corr(t_p_fillit *pack)
{
	if (pack->rows < 50)
		pack->zoom = 3;
	else
		pack->zoom = 1;
}

void		create_window(t_p_fillit *pack)
{
	t_image_pack	wnd;
	t_imgr			box;
	int				sz[2];

	wnd_sz(pack, &(sz[0]));
	wnd.p_mlx_win = mlx_init();
	sz[0] -= 10;
	sz[1] -= 10;
	wnd.p_win = mlx_new_window(wnd.p_mlx_win, sz[0], sz[1], "Spatial mapping");
	wnd.p_img = mlx_new_image(wnd.p_mlx_win, sz[0], sz[1]);
	wnd.p_table = M_T(wnd.p_img, &(wnd.bdd), &(wnd.size), &(wnd.endian));
	zoom_corr(pack);
	if (!(zoom_setting(wnd.p_table, pack, &sz[0])))
		window_error(pack->p_begin);
	mlx_put_image_to_window(wnd.p_mlx_win, wnd.p_win, wnd.p_img, 10, 25);
	key_info(&wnd, &sz[0]);
	box.sz = &sz[0];
	box.tb = &wnd;
	box.box = pack;
	mlx_hook(wnd.p_win, 17, (1L << 17), &destroy_window, pack->p_begin);
	mlx_hook(wnd.p_win, 2, (1L << 0), &pushed_key, &box);
	mlx_loop(wnd.p_mlx_win);
}
