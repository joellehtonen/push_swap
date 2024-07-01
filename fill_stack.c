/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:50:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/01 14:22:12 by jlehtone         ###   ########.fr       */
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
		str++;
	}
	return (result);
}

t_stack	*fill_stack(char **result, int i, t_stack **stack_a)
{
	long long	number;
	t_stack		*new;
	int			split_status;

	if (i == 0)
		split_status = 1;
	else
		split_status = 0;
	number = 0;
	while (result[i])
	{
		number = ft_atoll(result[i]);
		if (!check_min_max(number))
		{
			free_split(result);
			free_and_exit(stack_a, NULL, 1);
		}
		new = ft_lstnew_int(number);
		ft_lstadd_back_int(stack_a, new);
		i++;
	}
	if (split_status)
		free_split(result);
	return (*stack_a);
}

t_stack	*check_and_fill(int argc, char **argv, t_stack **stack_a)
{
	int			i;
	char		**result;

	i = 1;
	if (argc == 2)
	{
		result = ft_split(argv[i], ' ');
		i = 0;
	}
	else
		result = argv;
	if (!check_input(result, argc))
	{
		if (i == 0)
			free_split(result);
		free_and_exit(NULL, NULL, 1);
	}
	fill_stack(result, i, stack_a);
	check_duplicates(*stack_a);
	return (*stack_a);
}
