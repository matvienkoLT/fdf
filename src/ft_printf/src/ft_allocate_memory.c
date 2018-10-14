/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:16:56 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/28 11:28:13 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*g_all_specifier = "diupcsoxXfFDUOCS%eEgGnb";
const char		*g_all_p = " -+#0123456789*.hljztL";

typedef void	(*t_func_t)(t_flag **spec_f, va_list list);
t_func_t	g_func_type[23] = {(t_func_t)&va_arg_int, (t_func_t)&va_arg_int,
(t_func_t)&va_arg_unsgnt_int, (t_func_t)&va_arg_pointer,
(t_func_t)&va_arg_char, (t_func_t)&va_arg_string,
(t_func_t)&va_arg_octal, (t_func_t)&va_arg_hexa,
(t_func_t)&va_arg_hexaup, (t_func_t)&va_arg_float,
(t_func_t)&va_arg_floatup, (t_func_t)&va_arg_dup,
(t_func_t)&va_arg_uup, (t_func_t)&va_arg_oup,
(t_func_t)&va_arg_wchar_t, (t_func_t)&va_arg_sup,
(t_func_t)&arg_percent, (t_func_t)&va_arg_float_ef,
(t_func_t)&va_arg_float_ef, (t_func_t)&va_arg_float_ef,
(t_func_t)&va_arg_float_ef, (t_func_t)&arg_count,
(t_func_t)&var_arg_binary};

static void		ft_size_specifier(char **ptr_to_char, t_flag *spec_f)
{
	char	ptr[3];
	char	*str;
	int		status;

	str = *ptr_to_char;
	if ((status = ft_cmp_size(str, &ptr[0])))
	{
		if (spec_f->its_size && (ft_strcmp(spec_f->its_size, ptr) < 0))
			ft_strncpy(spec_f->size, ptr, 3);
		else if (!spec_f->its_size)
		{
			ft_strncpy(spec_f->size, ptr, 3);
			spec_f->its_size = spec_f->size;
		}
		if (status == 2)
			(*ptr_to_char)++;
	}
}

static void		ft_scfr_available(char **ptr, t_fl *fl, t_flag *list, va_list l)
{
	if (**ptr == '*')
		ft_check_star(&(**ptr), l, &list);
	else
		ft_size_specifier(&(*ptr), &(*list));
	*ptr = *ptr + 1;
	fl->ptr_s = (char*)g_all_specifier;
	fl->ptr_p = (char*)g_all_p;
}

static int		ft_its_com(char **ptr, t_fl *fl, t_flag *list, va_list l)
{
	while (**ptr != *fl->ptr_s)
	{
		if (**ptr == '\0')
			return (0);
		if (*fl->ptr_s == '\0')
		{
			if (*fl->ptr_p == **ptr)
				ft_scfr_available(&(*ptr), &(*fl), &(*list), l);
			else if (*fl->ptr_p == '\0')
				return (-1);
			else
				fl->ptr_p = fl->ptr_p + 1;
			continue;
		}
		fl->ptr_s = fl->ptr_s + 1;
	}
	return (1);
}

char			*ft_alloc_mem(char **format, t_flag *list, va_list l)
{
	short int	status;
	char		*ptr;
	t_fl		fl;
	char		*formated_data;

	ptr = *format;
	fl.ptr_p = (char *)g_all_p;
	fl.ptr_s = (char *)g_all_specifier;
	if ((status = ft_its_com(&ptr, &fl, &(*list), l)) == 1)
	{
		list->type = *fl.ptr_s;
		formated_data = ft_strnew((size_t)(ptr - *format + 1));
		g_func_type[fl.ptr_s - g_all_specifier](&list, l);
		return (ft_strncpy(formated_data, *format, ptr - *format + 1));
	}
	else if (status == -1)
	{
		ft_incorrect_spec(&(*format), &formated_data, &ptr, &(*list));
		return (ft_strncpy(formated_data, *format, ptr - *format + 1));
	}
	else
		*format = ptr;
	return (NULL);
}
