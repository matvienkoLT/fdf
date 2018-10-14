/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:13:18 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/04 10:06:16 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	argv;

	result = 0;
	va_start(argv, format);
	result = ft_print_while(2, format, &result, argv);
	va_end(argv);
	return (result);
}
