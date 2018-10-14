/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 10:12:09 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/13 10:40:34 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FTOA_H
# define FT_FTOA_H

# define LLI	long long int
# define LD		long double

# include "ft_printf.h"

typedef struct	s_f
{
	char		*ptr;
	LLI			bis_pnt;
	LLI			z;
	long double	p;
	char		*b_p;
	char		*n_p;
	char		*zero;

}				t_f;
LLI				ft_fpow(LD v, size_t deg, LD p);
char			*ft_negative_zero(char *bis_part);
LLI				ft_z_ch(LD n_t, size_t p);
LD				ft_precision(size_t pre);
LLI				ft_degree(int val, int cnt);
#endif
