/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:20:37 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/25 14:06:21 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>

# define BUFF_SIZE 1600

int	get_line(char **des, char **line);
int	get_next_line(const int fd, char **line);
int	status_line(char **des, char **line, int *status, int *bytes);
#endif
