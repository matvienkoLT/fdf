/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_description_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:35:09 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/18 16:37:17 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	sthing_error(int fd)
{
	ft_printf("{cyan}[ERROR]{eoc}Something unbelievable is happened:");
	ft_printf("{red}{bold}{unline}try check file on validity{eoc}\n");
	close(fd);
	exit(1);
}
