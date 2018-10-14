/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 19:57:28 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/10 09:43:12 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void		ft_initialization(t_p_fillit *ptr_pack)
{
	ft_memset(ptr_pack, 0, sizeof(t_p_fillit));
	ptr_pack->rows = 0;
	ptr_pack->width = 0;
	ptr_pack->z_min = 0;
	ptr_pack->z_max = 0;
	ptr_pack->zoom = 1;
	ptr_pack->angle_x = 1;
	ptr_pack->angle_y = 0;
	ptr_pack->max_y = 0;
	ptr_pack->min_y = 0;
	ptr_pack->max_x = 0;
	ptr_pack->min_x = 0;
	ptr_pack->z_v = 1;
	ptr_pack->gradient = 0;
	ptr_pack->swerve = 0.0;
}

static int		width_define(size_t *width, char **tab)
{
	int status;

	status = 1;
	if (*width == 0)
		*width = define_width_tab(tab);
	else if (define_width_tab(tab) != *width)
		status = 0;
	return (status);
}

static void		fd_reader(int fd)
{
	t_pixel_pack	*pk;
	t_p_fillit		ptr_pack;
	char			*p_string;
	char			**p_split_massive;

	ft_initialization(&ptr_pack);
	while (get_next_line(fd, &p_string) > 0)
	{
		if (!(p_split_massive = ft_strsplit(p_string, ' ')))
			sthing_error(fd);
		else
		{
			if (!(width_define(&(ptr_pack.width), p_split_massive)))
				width_error(p_split_massive, p_string, ptr_pack.p_begin);
			free(p_string);
			list_fillit(p_split_massive, &pk, &ptr_pack);
			tab_cleaner(p_split_massive);
			if (!(ptr_pack.p_high_elem))
				ptr_pack.p_high_elem = ptr_pack.p_begin;
			ptr_pack.rows++;
		}
	}
	if (ptr_pack.rows <= 1)
		sthing_error(fd);
	create_window(&ptr_pack);
}

static int		open_file(char *argv)
{
	int fd;

	fd = open(argv, O_RDONLY);
	return (fd);
}

int				ch_valid_name(char *argv)
{
	t_pixel_pack	*pk;
	char			*p_ftype;
	int				status;
	int				fd;

	status = 1;
	if (!(p_ftype = ft_strrchr(argv, '.')) ||
		ft_strcmp(p_ftype, ".fdf") != 0 || (fd = open_file(argv)) < 0)
		status = 0;
	else
	{
		fd_reader(fd);
	}
	return (status);
}
