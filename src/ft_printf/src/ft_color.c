/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:27:15 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/28 13:55:50 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_black(void)
{
	write(1, "\x1b[30m", 5);
}

void	ft_red(void)
{
	write(1, "\x1b[31m", 5);
}

void	ft_green(void)
{
	write(1, "\x1b[32m", 5);
}

void	ft_yellow(void)
{
	write(1, "\x1b[33m", 5);
}

void	ft_blue(void)
{
	write(1, "\x1b[34m", 5);
}
