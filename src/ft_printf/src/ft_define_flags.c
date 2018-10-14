/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:52:10 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/21 10:11:43 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *g_flags = "xXcCuUsSoO";

inline void	flag_minus(t_flag *spec_f)
{
	spec_f->its_minus = 1;
	spec_f->its_zero = 0;
}

inline void	flag_plus(t_flag *spec_f)
{
	spec_f->its_plus = 1;
	spec_f->its_space = 0;
}

void		flag_space(t_flag *spec_f)
{
	if (!spec_f->its_plus && !check_affect_for_type(&spec_f->type, g_flags) &&
		spec_f->type != -1)
	{
		spec_f->its_space = 1;
		spec_f->its_zero = 0;
	}
}

inline void	flag_hash(t_flag *spec_f)
{
	spec_f->its_hash = 1;
}

void		flag_zero(t_flag *spec_f)
{
	if (!spec_f->its_minus)
		spec_f->its_zero = 1;
}
