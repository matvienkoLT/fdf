/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:47:57 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/18 17:22:36 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H

# include <stdlib.h>
# include "mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

# define MAX_HEIGHT 10000
# define MIN_HEIGHT -10000
# define CUR_POS p_save_position
# define BEG_POS p_begin
# define P_B t_pixel_pack

typedef struct			s_image_pack
{
	int					bdd;
	int					endian;
	int					size;
	void				*p_mlx_win;
	void				*p_img;
	void				*p_win;
	char				*p_table;
}						t_image_pack;
typedef struct			s_pixel_pack
{
	int					z;
	int					x;
	int					y;
	int					x_mod;
	int					y_mod;
	struct s_pixel_pack	*n_node;
	struct s_pixel_pack	*h_node;
	int					rgb_color;
	short int			written;
}						t_pixel_pack;
typedef struct			s_p_fillit
{
	t_pixel_pack		*p_begin;
	t_pixel_pack		*p_save_position;
	t_pixel_pack		*p_high_elem;
	size_t				rows;
	size_t				width;
	int					z_max;
	int					z_min;
	float				zoom;
	int					z_v;
	int					angle_x;
	int					angle_y;
	int					move_x;
	int					move_y;
	int					max_y;
	int					min_y;
	int					max_x;
	int					min_x;
	int					step;
	int					gradient;
	float				swerve;
}						t_p_fillit;
typedef struct			s_cord_bre
{
	int					grd;
	int					dx;
	int					dy;
	int					err;
	int					ystep;
	int					y;
	int					x;
	int					sx;
	int					sy;
}						t_cord_bre;

typedef struct			s_imgr
{
	int					*sz;
	t_image_pack		*tb;
	t_p_fillit			*box;
}						t_imgr;

void					create_window(t_p_fillit *ptr_pack);
int						ch_valid_name(char *argv);
void					list_fillit(char **str, P_B **pk, t_p_fillit *pc);
int						z_cord_finder(char *str, t_p_fillit *p_pck, int i);
void					lst_cleaner(t_pixel_pack **pack);
void					tab_cleaner(char **tab);
size_t					define_width_tab(char **tab);
int						zoom_setting(char *im, t_p_fillit *lst, int *sz);
void					algorithm_bre(t_pixel_pack *block, int *im, int *sz);
void					algorithm_bre_v(P_B *block, int *im, int *sz, int *gr);
void					filling_color(int *color_bite, t_pixel_pack *block);
void					filling_grad_color(int *cb, P_B *bk, int *gr, int *i);
void					keyboard_zooming(int key, t_imgr *pack);
int						render(t_imgr *pack);
int						check_rotate(t_p_fillit *lst, int *sz);
int						ch_cord_pos(t_p_fillit *lst, P_B *pack, int *sz);
int						destroy_window(t_pixel_pack *p_begin);
int						pushed_key(int key, t_imgr *pack);
void					pushed_key_p(int key, t_imgr *pack);
void					key_info(t_image_pack *wnd, int *sz);
void					sthing_error(int fd);
void					ssymb_error(char **tab);
void					width_error(char **tab, char *ptr, t_pixel_pack *p_b);
void					window_error(t_pixel_pack *p_begin);
void					control_error(t_pixel_pack *p_begin);
#endif
