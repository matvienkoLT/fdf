/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpspecifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:50:05 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/28 11:30:08 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*g_all_flags = "-+ #";
const char		*g_all_size = "hljztL";
typedef void	(*t_func_f)(t_flag *spec_f);
t_func_f (g_func_flag[5]) = {(t_func_f)&flag_minus, (t_func_f)&flag_plus,
(t_func_f)&flag_space, (t_func_f)&flag_hash,
(t_func_f)&flag_zero};

static int	ft_cmp_flag(char *ptr_to_c, t_flag *spec_f)
{
	char	*ptr;

	ptr = (char *)g_all_flags;
	if (*ptr_to_c == 48 && *(ptr_to_c - 1) != '.')
	{
		g_func_flag[4](spec_f);
		return (1);
	}
	else if (*ptr_to_c > 48 && *ptr_to_c <= 57 && *(ptr_to_c - 1) != '.')
		return (10);
	else if (*ptr_to_c == '.')
		return (flag_dot(ptr_to_c, &spec_f));
	else if (*ptr_to_c == '*')
		return (1);
	while (*ptr != '\0')
	{
		if (*ptr_to_c == *ptr)
		{
			g_func_flag[ptr - g_all_flags](spec_f);
			return (1);
		}
		ptr++;
	}
	return (0);
}

static int	ft_cmp_sz(char *ptr_to_char)
{
	char	*ptr;

	ptr = (char *)g_all_size;
	if ((*ptr_to_char == 'h' && *(ptr_to_char + 1) == 'h') ||
		(*ptr_to_char == 'l' && *(ptr_to_char + 1) == 'l'))
		return (2);
	while (*ptr != '\0')
	{
		if (*ptr_to_char == *ptr)
			return (1);
		ptr++;
	}
	return (0);
}

static int	ft_dgt_quntt(unsigned int n)
{
	int	quantt;

	if (n == 0)
		return (1);
	quantt = 0;
	while (n > 0)
	{
		n /= 10;
		quantt++;
	}
	return (quantt);
}

static char	*ft_check_width(char *ptr, t_flag *spec_f)
{
	size_t str;

	if (!spec_f->its_star_w)
	{
		str = ft_atoi(ptr);
		spec_f->its_width = str;
	}
	else
		str = ft_atoi(ptr);
	return (ptr + ft_dgt_quntt(str) - 1);
}

void		add_format_param(char *format, t_flag *spec_f)
{
	int		status;
	char	*ptr;

	ptr = format;
	spec_f->len_v = ft_strlen(spec_f->value);
	while (*ptr != '\0')
	{
		if (!(status = ft_cmp_flag(ptr, spec_f)))
		{
			if ((status = ft_cmp_sz(ptr)) == 2)
				ptr++;
			else if (status == 0)
				return ;
		}
		else if (status == 2)
			ptr += (ft_dgt_quntt(spec_f->precision));
		else if (status == 10)
			ptr = ft_check_width(&(*ptr), &(*spec_f));
		ptr++;
	}
}
