/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:01:12 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/30 17:27:23 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_integer(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit((int)argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_min_max(char *argv)
{
	int	i;
	int	result;

	result = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) >= 10)
		{
			result = ft_atoi(argv[i]);
			if (result == 0 || result == -1)
				return (0);
		}
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

int	check_correct_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_if_integer(argv[i]))
			return (0);
		if (!check_min_max(argv[i]))
			return (0);
		i++;
	}
	if (!check_duplicates(argv))
		return (0);
	return (1);
}
