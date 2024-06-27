/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:01:12 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/27 16:57:20 by jlehtone         ###   ########.fr       */
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

void	check_min_max(t_stack *stack_a, long long number)
{
	if (number > INT_MAX || number < INT_MIN)
		free_and_exit(&stack_a, NULL, 1);
}

void	check_integer(char *argv)
{
	int	i;

	i = 0;
	if (!*argv)
		free_and_exit(NULL, NULL, 1);
	if (argv[i] == '+' || argv[i] == '-')
	{
		i++;
		if (!argv[i])
			free_and_exit(NULL, NULL, 1);
	}
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			free_and_exit(NULL, NULL, 1);
		i++;
	}
}

void	check_input(char **argv, int argc)
{
	int	i;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	if (!argv[0])
		return ;
	while (argv[i])
	{
		check_integer(argv[i]);
		i++;
		argc--;
	}
}
