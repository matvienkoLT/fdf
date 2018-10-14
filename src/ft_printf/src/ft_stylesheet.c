/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stylesheet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:00:48 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/29 10:45:01 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_underline(void)
{
	write(1, "\x1b[4m", 5);
}

void	ft_underlineoff(void)
{
	write(1, "\x1b[24m", 5);
}

void	ft_bold(void)
{
	write(1, "\x1b[1m", 5);
}

void	ft_boldoff(void)
{
	write(1, "\x1b[21m", 5);
}

void	ft_eoc(void)
{
	write(1, "\x1b[0m", 5);
}
