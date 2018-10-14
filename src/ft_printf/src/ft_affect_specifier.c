/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affect_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:04:45 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/01 17:38:34 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_prec_ups(t_flag *box)
{
	char	*string;
	size_t	tt;
	int		ch;

	string = box->value;
	tt = box->precision;
	if (box->precision > box->len_v)
		box->precision = box->len_v;
	else if (((unsigned char)string[tt] >> 6) == 0x2)
	{
		ch = ((unsigned char)string[--tt] >> 6);
		while (ch == 0x2)
			ch = ((unsigned char)string[--tt] >> 6);
		box->precision = tt;
	}
}

void			ft_print_char(int *sym, char c)
{
	write(1, &c, 1);
	(*sym)++;
}

static	void	ft_print_string(t_flag *box, int *sym)
{
	char	*string;
	size_t	tt;

	string = box->value;
	tt = 0;
	while (tt < box->precision && string[tt] != '\0')
	{
		tt++;
		(*sym)++;
	}
	write(1, string, tt);
}

static void		ft_affect_short_f(t_flag *box, int *sym)
{
	char	*ptr;
	size_t	step;

	step = box->precision + 1;
	ptr = box->value;
	while (*ptr != '\0' && *ptr != '.')
		ptr++;
	if (*ptr == '.' || *ptr == '0')
	{
		while (*ptr != '\0' && step != 0)
		{
			ptr++;
			step--;
		}
	}
	*ptr = '\0';
	while (*(--ptr) == '0' || *(ptr) == '.')
		*ptr = '\0';
	box->len_v = ft_strlen(box->value);
	write(1, box->value, box->len_v);
	*sym += box->len_v;
}

void			ft_affect_specifier(t_flag *box, int *sym)
{
	char	*string;

	if (box->type == 'n')
		*((box)->address) = *sym;
	else if ((box->type == 's' || box->type == 'S') && box->its_dot)
		ft_print_string(box, &(*sym));
	else if ((box->its_hash && box->type == 'o' && !ft_strcmp(box->value, "0")))
		return ;
	else if (box->precision == 0 && box->its_dot && !ft_strcmp(box->value, "0"))
		return ;
	else if ((box->type == 'c' || box->type == 'C') && *box->value == '\0')
		ft_print_char(&(*sym), '\0');
	else if ((box->type == 'g' || box->type == 'G') && !box->its_scientific_f)
		ft_affect_short_f(&(*box), &(*sym));
	else
	{
		string = box->value;
		write(1, string, box->len_v);
		*sym += box->len_v;
	}
}
