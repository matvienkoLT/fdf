/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afect_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:49:35 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/26 11:31:52 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*g_flag_precision = "dDioOuUxX";
static char	*g_flag_precision_p = "p";
#define LLI long long int

static void	ft_correction_tools_minus(t_flag *box, LLI *tt, LLI len)
{
	if (box->precision)
		*tt = FT_ABS(len - (LLI)box->precision) + len;
	else
		*tt = len;
	if (box->its_float && box->its_value_negative)
	{
		*tt = len;
		*tt = (LLI)box->its_width - *tt;
	}
	else
	{
		if (box->its_float)
			*tt = len;
		*tt = (LLI)box->its_width - *tt;
		if (!box->its_value_negative)
			*tt -= (box->its_plus + box->its_space);
		else
			*tt -= box->its_value_negative;
	}
}

static void	ft_correct_tools_str(t_flag *box, LLI *tt, size_t len)
{
	if (len > box->precision && box->its_dot)
		len = box->precision;
	*tt = (LLI)box->its_width - len;
}

void		ft_affect_minus(t_flag *box, int *sym)
{
	LLI tt;
	LLI len;

	if (box->its_minus > 0 && box->its_width > 0)
	{
		len = (LLI)box->len_v;
		ft_corr_tools_type(&(*box), &len);
		if (box->type == 's' && box->its_dot)
			ft_correct_tools_str(&(*box), &tt, len);
		else
			ft_correction_tools_minus(&(*box), &tt, len);
		while (tt-- > 0)
		{
			write(1, " ", 1);
			(*sym)++;
		}
	}
}

int			check_affect_for_type(char *ch, char *g_flag)
{
	char		*ptr;

	ptr = g_flag;
	while (*ptr != *ch && *ptr != '\0')
		ptr++;
	if (*ptr == *ch)
		return (1);
	else
		return (0);
}

void		ft_affect_precision(t_flag *box, int *sym)
{
	LLI				tt;
	short int		st;

	if ((tt = box->precision - box->len_v) > 0 &&
		check_affect_for_type(&(box->type), g_flag_precision))
	{
		while (tt-- > 0)
			ft_print_char(&(*sym), '0');
	}
	else if ((st = check_affect_for_type(&(box->type), g_flag_precision_p)))
	{
		write(1, "0x", 2);
		(*sym) += 2;
		while (tt-- > 0)
			ft_print_char(&(*sym), '0');
	}
}
