/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:31:23 by lmatvien          #+#    #+#             */
/*   Updated: 2018/04/04 17:45:25 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

size_t				ft_strlen(const char *str);
size_t				ft_strnlen(char const *str, char c);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *str, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *str, const char *source, size_t num);
char				*ft_strcat(char *str, const char *source);
char				*ft_strnew(size_t size);
void				*ft_memset(void *str, int c, size_t n);
int					get_next_line(const int fd, char **line);
int					ft_isdigit(int c);
char				**ft_strsplit(char const *s, char c);
int					ft_atoi(const char *argv);
int					ft_atoi_base(char *str, int base);
void				ft_swap(int *a, int *b);
#endif
