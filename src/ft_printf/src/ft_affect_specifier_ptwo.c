/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affect_specifier_ptwo.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 17:28:54 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/01 17:40:50 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	var_arg_binary(t_flag **spec_f, va_list list)
{
	int value;

	value = va_arg(list, unsigned int);
	(*spec_f)->value = ft_ulltoa_base(value, 2);
}
