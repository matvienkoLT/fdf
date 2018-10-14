/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:24:08 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/21 11:03:23 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

size_t		define_width_tab(char **tab)
{
	size_t	sz;

	sz = 0;
	if (tab)
	{
		while (*tab)
		{
			sz++;
			tab++;
		}
	}
	return (sz);
}

static void	rgb_clr_fn(char *str, int *color, int z)
{
	int i;

	if (str)
	{
		if ((str = ft_strstr(str, "0x")))
			*color = ft_atoi_base(str + 2, 16);
		else if (z > 0)
			*color = 0xFFFFFF;
	}
}

int			z_cord_finder(char *str, t_p_fillit *p_pck, int i)
{
	int	z;

	if (ft_isdigit(*str) || (*str == '-' && ft_isdigit(*(str + 1))))
	{
		z = ft_atoi(str);
		if (!(z > MAX_HEIGHT || z < MIN_HEIGHT))
		{
			p_pck->p_save_position->z = z;
			if (z < p_pck->z_min)
				p_pck->z_min = z;
			else if (z > p_pck->z_max)
				p_pck->z_max = z;
			p_pck->p_save_position->x = i;
			p_pck->p_save_position->y = p_pck->rows;
			p_pck->p_save_position->written = 1;
			rgb_clr_fn(ft_strchr(str, ','), &p_pck->CUR_POS->rgb_color, z);
		}
		else
		{
			lst_cleaner(&(p_pck->p_begin));
			return (0);
		}
	}
	return (1);
}
