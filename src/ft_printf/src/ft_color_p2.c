/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:21:55 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/28 13:56:53 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_magenta(void)
{
	write(1, "\x1b[35m", 5);
}

void	ft_cyan(void)
{
	write(1, "\x1b[36m", 5);
}

void	ft_white(void)
{
	write(1, "\x1b[37m", 5);
}

void	ft_default(void)
{
	write(1, "\x1b[39m", 5);
}

void	ft_lwhite(void)
{
	write(1, "\x1b[97m", 5);
}
