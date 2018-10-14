/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:00:32 by lmatvien          #+#    #+#             */
/*   Updated: 2018/06/04 10:00:35 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *str, const char *source)
{
	char	*destination;

	destination = str;
	while (*destination != '\0')
		destination++;
	while (*source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
	return (str);
}
