/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afect_flags_psecond.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:31:47 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/26 11:33:59 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define LLI long long int

static void	ft_correction_tools_width(t_flag *box, LLI *tt, LLI len, int *sym)
{
	if (box->precision && ((LLI)box->precision >= len))
		*tt = FT_ABS(len - (LLI)box->precision) + len;
	else
		*tt = len;
	*tt = (LLI)box->its_width - *tt;
	*tt -= box->its_plus;
	if (!box->its_plus && box->its_value_negative)
		*tt -= box->its_value_negative;
	if (!box->its_plus && box->its_space && box->type != '%' &&
		box->type != 'p' && !box->its_value_negative && *tt <= 0 &&
		!box->its_zero)
	{
		(*sym)++;
		write(1, " ", 1);
	}
}

static void	ft_correct_tools_str(t_flag *box, LLI *tt, size_t len)
{
	if (len > box->precision && box->its_dot)
		len = box->precision;
	*tt = (LLI)box->its_width - len;
}

static void	ft_ch_space(t_flag *box, LLI *tt, int *sym, char *ch)
{
	if (box->its_space && box->its_zero && !box->its_dot &&
		!box->precision && !box->its_value_negative &&
		box->type != '%')
	{
		write(1, " ", 1);
		(*sym)++;
		(*tt)--;
	}
	if (box->its_zero && !box->its_dot && !box->precision)
		*ch = '0';
	if (box->its_zero && !box->precision && box->type != 'o'
		&& box->type != 'O')
		*ch = '0';
}

static void	ft_corr_char_print(int *sym, char ch)
{
	(*sym)++;
	write(1, &ch, 1);
}

void		ft_affect_width(t_flag *box, int *sym)
{
	LLI		tt;
	LLI		len;
	char	ch;

	ch = ' ';
	if (box->its_minus == 0 && !box->its_float)
	{
		len = (LLI)box->len_v;
		ft_corr_tools_type(&(*box), &len);
		if ((box->type == 's' || box->type == 'S') && box->its_dot)
			ft_correct_tools_str(box, &tt, (size_t)len);
		else
			ft_correction_tools_width(&(*box), &tt, len, &(*sym));
		ft_ch_space(&(*box), &tt, &(*sym), &ch);
		while (tt-- > 0)
			ft_corr_char_print(&(*sym), ch);
	}
	else if (box->its_minus && box->its_space &&
		!box->its_value_negative)
		ft_corr_char_print(&(*sym), ch);
}
