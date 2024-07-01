/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:01:12 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/01 11:51:20 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stack *stack_a)
{
	t_stack	*check;
	t_stack	*compare;

	check = stack_a;
	compare = stack_a;
	while (check)
	{
		compare = check->next;
		while (compare)
		{
			if (check->content == compare->content)
				free_and_exit(&stack_a, NULL, 1);
			compare = compare->next;
		}
		check = check->next;
	}
}

int	check_min_max(long long number)
{
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	else
		return (1);
}

int	check_integer(char *argv)
{
	int	i;

	i = 0;
	if (!*argv)
		return (0);
	if (argv[i] == '+' || argv[i] == '-')
	{
		i++;
		if (!argv[i])
			return (0);
	}
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char **argv, int argc)
{
	int	i;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	if (!argv[0])
		return (1);
	while (argv[i])
	{
		if (!check_integer(argv[i]))
			return (0);
		i++;
		argc--;
	}
	return (1);
}
