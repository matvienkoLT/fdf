/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:11:59 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/29 10:43:50 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef void	(*t_color)(void);
t_color g_color[20] = {(t_color)&ft_black, (t_color)&ft_red, (t_color)&ft_green,
(t_color)&ft_yellow, (t_color)&ft_blue, (t_color)&ft_magenta,
(t_color)&ft_cyan, (t_color)&ft_white, (t_color)&ft_default,
(t_color)&ft_lwhite, (t_color)&ft_underline, (t_color)&ft_underlineoff,
(t_color)&ft_bold, (t_color)&ft_boldoff, (t_color)&ft_eoc,
(t_color)&ft_b_yellow, (t_color)&ft_b_gray, (t_color)&ft_b_white,
(t_color)&ft_b_green, (t_color)&ft_b_cyan};
static char *g_available_color[20] = {"{black}", "{red}", "{green}",
	"{yellow}", "{blue}", "{magenta}", "{cyan}",
	"{white}", "{default}", "{lwhite}", "{unline}",
	"{unlineoff}", "{bold}", "{boldoff}", "{eoc}",
	"{byellow}", "{bgray}", "{bwhite}",
	"{bgreen}", "{bcyan}"};

typedef char*	(*t_func_flag)(char *ptr_char, va_list list, char *f);

static int	ft_locale_check(t_flag *box, char *specifiers, int *sym)
{
	if (box->type == 'S' && MB_CUR_MAX == 1)
	{
		free_memory(&(*box), specifiers, &(*sym));
		return (0);
	}
	add_format_param(specifiers, &(*box));
	ft_affect_float(&(*box));
	if (box->type == 'C' && MB_CUR_MAX == 1)
	{
		free_memory(&(*box), specifiers, &(*sym));
		return (0);
	}
	ft_summarize(&(*box), &(*sym));
	return (1);
}

static char	*ft_vfprintf(char **ptr_f, va_list list, int *sym)
{
	char	*specifiers;
	t_flag	spec_f;
	size_t	len_spec;

	ft_memset(&spec_f, 0, sizeof(t_flag));
	if (!(specifiers = ft_alloc_mem(&(*ptr_f), &spec_f, list)))
		return (*ptr_f);
	len_spec = ft_strlen(specifiers);
	if (!ft_locale_check(&spec_f, specifiers, &(*sym)))
		return (*ptr_f + len_spec);
	free(specifiers);
	return (*ptr_f + len_spec);
}

static int	ft_color(char **ptr, int *sym)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (!ft_colorcmp(*ptr, g_available_color[i]))
		{
			g_color[i]();
			(*sym) += 5;
			*ptr += ft_strlen(g_available_color[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_print_while(int fd, const char *format, int *sym, va_list list)
{
	char	*ptr_f;

	ptr_f = (char*)format;
	while (*ptr_f != '\0')
	{
		if (*ptr_f == '%')
		{
			ptr_f++;
			ptr_f = ft_vfprintf(&ptr_f, list, &(*sym));
		}
		else
		{
			if (*ptr_f == '{')
			{
				if (ft_color(&ptr_f, &(*sym)))
					continue ;
			}
			write(fd, ptr_f, 1);
			ptr_f++;
			(*sym)++;
		}
	}
	return (*sym);
}
