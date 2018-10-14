/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_description.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:43:06 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/18 16:37:56 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

int		destroy_window(t_pixel_pack *p_begin)
{
	ft_printf("{red}{bold}{unline}Exit. See you soon!{eoc}\n");
	lst_cleaner(&p_begin);
	exit(1);
	return (1);
}

void	window_error(t_pixel_pack *p_begin)
{
	ft_printf("{cyan}[ERROR]{eoc}Something unbelievable is happened:");
	ft_printf("{red}{bold}{unline}try check file on validity{eoc}\n");
	lst_cleaner(&p_begin);
	exit(1);
}

void	ssymb_error(char **tab)
{
	ft_printf("{cyan}[ERROR]{eoc}Something unbelievable is happened:");
	ft_printf("{red}{bold}{unline}undefined symbol{eoc}\n");
	tab_cleaner(tab);
	exit(1);
}

void	width_error(char **tab, char *ptr, t_pixel_pack *p_begin)
{
	ft_printf("{cyan}[ERROR]{eoc}Something unbelievable is happened:");
	ft_printf("{red}{bold}{unline}undefined maps width{eoc}\n");
	tab_cleaner(tab);
	lst_cleaner(&p_begin);
	free(ptr);
	exit(1);
}

void	control_error(t_pixel_pack *p_begin)
{
	ft_printf("{red}{bold}{unline}Control error!{eoc}\n");
	lst_cleaner(&p_begin);
	exit(1);
}
