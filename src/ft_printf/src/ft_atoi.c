/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:33:41 by lmatvien          #+#    #+#             */
/*   Updated: 2018/05/31 10:56:46 by lmatvien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX 922337203685477580

static int	double_sign(const char *argv)
{
	if ((*argv != '+' && *argv != '-') && (*argv < 48 || *argv > 57))
		return (1);
	argv++;
	if ((*argv < 48 || *argv > 57) && *argv != '\0')
		return (1);
	return (0);
}

static int	minus_indicator(const char *argv)
{
	int minus;

	if (*argv == '-')
	{
		minus = -1;
		argv++;
	}
	else
		minus = 1;
	return (minus);
}

int			ft_atoi(const char *argv)
{
	long long int	value;
	int				minus;

	value = 0;
	while ((*argv >= 9 && *argv <= 13) || *argv == 32)
		argv++;
	minus = minus_indicator(argv);
	if ((*argv < 48 || *argv > 57) && double_sign(argv))
		return (0);
	while (*argv != '\0')
	{
		if (minus < 0 && (value > MAX || (value == MAX && *argv > '7')))
			return (0);
		else if (value > MAX || (value == MAX && *argv > '7'))
			return (-1);
		if (*argv >= 48 && *argv <= 57)
		{
			value = value * 10 + (*argv - '0');
			if (*(argv + 1) < 48 || *(argv + 1) > 57)
				break ;
		}
		argv++;
	}
	return (value * minus);
}
