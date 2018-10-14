/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:06:16 by lmatvien          #+#    #+#             */
/*   Updated: 2018/07/01 17:39:23 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define FT_ABS(x) (((x)<0)?-(x):(x))

const char		*g_all_specifier;
const char		*g_all_size;

typedef struct	s_specifiers
{
	long double	float_val;
	size_t		its_width;
	short int	its_float;
	short int	its_minus;
	short int	its_plus;
	short int	its_space;
	short int	its_hash;
	short int	its_zero;
	short int	its_dot;
	short int	its_star_w;
	short int	its_star_s;
	short int	its_value_negative;
	short int	its_scientific_f;
	size_t		precision;
	char		type;
	char		size[3];
	char		*its_size;
	char		*value;
	size_t		len_v;
	int			*address;
}				t_flag;
typedef struct	s_fl
{
	char		*ptr_s;
	char		*ptr_p;

}				t_fl;
typedef struct	s_eformat
{
	int			degree;
	int			mant;
	char		*bhvr;
	char		*per_dot;
}				t_eformat;
int				ft_printf(const char *format, ...);
int				ft_print_while(int fd, const char *ft, int *s, va_list ls);
void			ft_settings_float(t_flag **box);
void			*ft_memset(void *str, int c, size_t n);
size_t			ft_strlen(const char *str);
size_t			ft_wcstrlen(wchar_t *s);
char			*ft_strnew(size_t size);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *str, const char *source);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *argv);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, unsigned int base);
char			*ft_ulltoa_base(unsigned long long value, unsigned int base);
char			*ft_lltoa(long long int n);
char			*ft_ftoa(long double v, size_t precision);
char			*ft_ftoa_scast(long double v, size_t pre);
int				ft_num_digit(long long int n);
char			*ft_alloc_mem(char **f, t_flag *list, va_list l);
void			add_format_param(char *format, t_flag *spec_f);
int				ft_cmp_size(char *ptr_to_char, char *size);
int				check_affect_for_type(char *ch, char *g_flag);
void			ft_incorrect_spec(char **f, char **fo, char **ptr, t_flag *l);
int				str_wchar(int value, t_flag **spec_f);
void			va_arg_int(t_flag **spec_f, va_list list);
void			va_arg_unsgnt_int(t_flag **spec_f, va_list list);
void			va_arg_dup(t_flag **spec_f, va_list list);
void			va_arg_pointer(t_flag **spec_f, va_list list);
void			va_arg_char(t_flag **spec_f, va_list list);
void			va_arg_string(t_flag **spec_f, va_list list);
void			va_arg_octal(t_flag **spec_f, va_list list);
void			va_arg_hexa(t_flag **spec_f, va_list list);
void			va_arg_hexaup(t_flag **spec_f, va_list list);
void			va_arg_float(t_flag **spec_f, va_list list);
void			va_arg_floatup(t_flag **spec_f, va_list list);
void			va_arg_uup(t_flag **spec_f, va_list list);
void			va_arg_oup(t_flag **spec_f, va_list list);
void			va_arg_sup(t_flag **spec_f, va_list list);
void			va_arg_wchar_t(t_flag **spec_f, va_list list);
void			va_arg_float_ef(t_flag **spec_f, va_list list);
void			var_arg_binary(t_flag **spec_f, va_list list);
void			arg_count(t_flag **spec_f, va_list list);
void			arg_percent(t_flag **spec_f, va_list list);
void			flag_minus(t_flag *spec_f);
void			flag_plus(t_flag *spec_f);
void			flag_space(t_flag *spec_f);
void			flag_hash(t_flag *spec_f);
void			flag_zero(t_flag *spec_f);
int				flag_dot(char *ptr, t_flag **spec_f);
void			ft_check_star(char *ptr, va_list l, t_flag **spec_f);
void			ft_summarize(t_flag *box, int *sym);
void			ft_affect_minus(t_flag *box, int *sym);
char			*ft_scientific_format(t_flag **spec_f);
char			*ft_short_float_format(t_flag **spec_f);
void			ft_corr_tools_type(t_flag *box, long long int *len);
void			ft_affect_precision(t_flag *box, int *sym);
void			ft_affect_plus(t_flag *box, int *sym);
void			ft_affect_specifier(t_flag *box, int *sym);
void			ft_affect_width(t_flag *box, int *sym);
void			ft_affect_space(t_flag *box, int *sym);
void			ft_affect_float(t_flag *box);
void			ft_affect_hash(t_flag *box, int *sym);
void			ft_affect_width_float(t_flag *box, int *sym);
void			ft_printf_prec_ups(t_flag *box);
void			ft_wcstr_negativ_signed(char *ptr, t_flag **box);
int				free_memory(t_flag *box, char *specifiers, int *sym);
void			ft_print_char(int *sym, char c);
int				ft_colorcmp(const char *s1, const char *s2);
void			ft_black(void);
void			ft_red(void);
void			ft_green(void);
void			ft_yellow(void);
void			ft_blue(void);
void			ft_magenta(void);
void			ft_cyan(void);
void			ft_white(void);
void			ft_default(void);
void			ft_lwhite(void);
void			ft_underline(void);
void			ft_underlineoff(void);
void			ft_bold(void);
void			ft_boldoff(void);
void			ft_eoc(void);
void			ft_b_yellow(void);
void			ft_b_gray(void);
void			ft_b_white(void);
void			ft_b_green(void);
void			ft_b_cyan(void);
#endif
