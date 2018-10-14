/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_summarize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:50:05 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/21 10:09:06 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_correction_hash(t_flag *box, int *sym)
{
	if (box->its_zero)
	{
		ft_affect_hash(&(*box), &(*sym));
		ft_affect_plus(&(*box), &(*sym));
		ft_affect_width(&(*box), &(*sym));
	}
	else
	{
		ft_affect_width(&(*box), &(*sym));
		ft_affect_hash(&(*box), &(*sym));
		ft_affect_plus(&(*box), &(*sym));
	}
}

static void	ft_correction_precision(t_flag *box, int *sym)
{
	if (box->its_zero && box->type == 'p')
	{
		ft_affect_precision(&(*box), &(*sym));
		ft_correction_hash(box, &(*sym));
	}
	else
	{
		ft_correction_hash(box, &(*sym));
		ft_affect_precision(&(*box), &(*sym));
	}
}

void		ft_summarize(t_flag *box, int *sym)
{
	ft_affect_width_float(&(*box), &(*sym));
	if (box->type == 'S' && box->precision)
		ft_printf_prec_ups(&(*box));
	ft_correction_precision(&(*box), &(*sym));
	ft_affect_specifier(&(*box), &(*sym));
	ft_affect_minus(&(*box), &(*sym));
	if (box->value)
		free(box->value);
}
