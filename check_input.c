/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:01:12 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/07 09:42:59 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0') * sign;
		if (result < 0 && sign > 0)
			return (-1);
		else if (result > 0 && sign < 0)
			return (0);
		str++;
	}
	return (result);
}

int	check_integer(char *argv)
{
	int			i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '+' || argv[i] == '-')
			i++;
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strncmp(argv[i], argv[j], 11))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_integer(argv[i]))
			return (0);
		i++;
	}
	if (!check_duplicates(argv))
		return (0);
	return (1);
}
