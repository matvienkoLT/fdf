/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:27:35 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/08 20:38:52 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

int	main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_printf("{cyan}[ERROR]{eoc}incorrect input data ->");
		ft_printf("{red}{bold}{unline}./fdf name_map{eoc}\n");
	}
	else if (!ch_valid_name(argv[1]))
	{
		ft_printf("{cyan}[ERROR]{eoc}file doesn't exist or cannot ");
		ft_printf("be visited normally -> ");
		ft_printf("{red}{bold}{unline}./fdf *.fdf{eoc}\n");
	}
	return (0);
}
