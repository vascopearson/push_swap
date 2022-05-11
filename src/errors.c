/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:33:16 by vserrao-          #+#    #+#             */
/*   Updated: 2022/05/11 16:15:23 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_nbr(int argc, char **argv)
{
	int	size;

	size = argc - 1;
	while (size > 0)
	{
		if (!ft_isdigit_(argv[size]))
			return (0);
		size--;
	}
	return (1);
}

int	ft_duplicates(int argc, char **argv)
{
	int	size;
	int	pos;

	size = argc - 1;
	pos = size - 1;
	while (size > 0)
	{
		while (pos > 0)
		{
			if (ft_atoi_(argv[size]) == ft_atoi_(argv[pos]))
				return (1);
			pos--;
		}
		size--;
		pos = size - 1;
	}
	return (0);
}

int	ft_nbr_in_range(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		if (ft_atoi_(argv[i]) < MIN_INT || ft_atoi_(argv[i]) > MAX_INT)
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi_(const char *str)
{
	long int	x;
	long int	neg;
	long int	n;

	x = 0;
	neg = 1;
	n = 0;
	while ((str[x] >= 9 && str [x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			neg *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		n = (str[x] - '0') + (n * 10);
		x++;
	}
	return (n * neg);
}

int	ft_isdigit_(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-')
		i++;
	while (nbr[i])
	{
		if (!(nbr[i] >= 48 && nbr[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}
