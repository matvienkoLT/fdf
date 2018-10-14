/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:03:58 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/01 11:23:59 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ftoa.h"

static void	ft_destroy_obj(t_f *prm)
{
	free(prm->b_p);
	free(prm->n_p);
	free(prm->zero);
}

char		*ft_ftoa(LD v, size_t pre)
{
	t_f	prm;
	LLI h;

	prm.p = ft_precision(pre);
	prm.bis_pnt = (LLI)v;
	prm.b_p = ft_lltoa(prm.bis_pnt);
	if (pre == 0)
		return (prm.b_p);
	if (v < 0 && prm.bis_pnt == 0)
		prm.b_p = ft_negative_zero(prm.b_p);
	h = FT_ABS(ft_fpow((v - (LD)prm.bis_pnt), pre, prm.p));
	prm.n_p = ft_lltoa(h);
	prm.z = ft_z_ch((v - (LD)prm.bis_pnt), pre);
	prm.ptr = ft_strnew(ft_strlen(prm.b_p) + ft_strlen(prm.n_p) + prm.z + 1);
	prm.ptr = ft_strcat(prm.ptr, prm.b_p);
	prm.zero = ft_memset(ft_strnew(prm.z), '0', prm.z);
	prm.ptr = ft_strcat(ft_strcat(prm.ptr, "."), prm.zero);
	prm.ptr = ft_strcat(prm.ptr, prm.n_p);
	ft_destroy_obj(&prm);
	return (prm.ptr);
}

char		*ft_ftoa_scast(LD v, size_t pre)
{
	t_f	prm;
	LLI h;

	prm.bis_pnt = (LLI)v;
	prm.b_p = ft_lltoa(prm.bis_pnt);
	h = ft_num_digit(v);
	if (pre == 0)
		return (prm.b_p);
	if (v < 0 && prm.bis_pnt == 0)
		prm.b_p = ft_negative_zero(prm.b_p);
	if (pre >= (size_t)h)
		h = pre - h;
	else
		h = pre;
	prm.p = ft_precision(pre);
	h = FT_ABS(ft_fpow((v - (LD)prm.bis_pnt), pre, prm.p));
	prm.n_p = ft_lltoa(h);
	prm.z = ft_z_ch((v - (LD)prm.bis_pnt), pre);
	prm.ptr = ft_strnew(ft_strlen(prm.b_p) + ft_strlen(prm.n_p) + prm.z + 1);
	prm.ptr = ft_strcat(prm.ptr, prm.b_p);
	prm.zero = ft_memset(ft_strnew(prm.z), '0', prm.z);
	prm.ptr = ft_strcat(ft_strcat(prm.ptr, "."), prm.zero);
	prm.ptr = ft_strcat(prm.ptr, prm.n_p);
	ft_destroy_obj(&prm);
	return (prm.ptr);
}
