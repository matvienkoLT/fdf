/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:49:37 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/25 13:47:59 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	get_line(char **des, char **line)
{
	size_t	end_l;
	char	*temp;

	if (!(*des) || **des == '\0')
		return (-1);
	if (**des == '\n')
	{
		*line = ft_strcpy(ft_strnew(1), "\0");
		temp = ft_strcpy(ft_strnew(BUFF_SIZE - 1), *des + 1);
		free(*des);
		*des = temp;
		return (1);
	}
	if ((end_l = ft_strnlen(*des, '\n')))
	{
		*line = ft_strncat(ft_strnew(end_l), *des, end_l);
		temp = ft_strcpy(ft_strnew(ft_strlen(*des) - end_l), *des + end_l + 1);
		free(*des);
		*des = temp;
		return (1);
	}
	return (0);
}

int	status_line(char **des, char **line, int *status, int *bytes)
{
	if (*status == 1)
		return (1);
	if (*bytes < 0)
		return (-1);
	if ((*status = get_line(des, line)) == 0)
	{
		*line = *des;
		*des = NULL;
		return (1);
	}
	else if (*status > 0)
		return (1);
	else
		*line = NULL;
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	int				status;
	int				bytes;
	static char		*des[256];
	char			*buffer;
	char			*temp;

	if (fd < 0 || fd > 256 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if ((status = get_line(&des[fd], line)) == 1)
		return (1);
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		temp = ft_strjoin(des[fd], buffer);
		free(des[fd]);
		des[fd] = temp;
		if ((status = get_line(&des[fd], line)) == 1)
			break ;
	}
	free(buffer);
	return (status_line(&des[fd], &(*line), &status, &bytes));
}
