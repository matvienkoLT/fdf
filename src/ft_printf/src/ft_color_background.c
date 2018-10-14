/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:21:38 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/29 10:46:04 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_b_yellow(void)
{
	write(1, "\x1b[43m", 5);
}

void	ft_b_gray(void)
{
	write(1, "\x1b[49m", 5);
}

void	ft_b_white(void)
{
	write(1, "\x1b[47m", 5);
}

void	ft_b_green(void)
{
	write(1, "\x1b[42m", 5);
}

void	ft_b_cyan(void)
{
	write(1, "\x1b[46m", 5);
}
