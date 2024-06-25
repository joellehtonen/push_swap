/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:50:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/25 10:08:02 by jlehtone         ###   ########.fr       */
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

t_stack	*fill_stack(int argc, char **argv, t_stack **stack_a)
{
	int			i;
	long long	number;
	char		**result;
	t_stack		*new;

	i = 1;
	number = 0;
	if (argc == 2)
	{
		result = ft_split(argv[i], ' ');
		i = 0;
	}
	else
		result = argv;
	check_input(result, argc);
	while (result[i])
	{
		number = ft_atoll(result[i]);
		check_min_max(stack_a, number);
		new = ft_lstnew_int(number);
		ft_lstadd_back_int(stack_a, new);
		i++;
	}
	check_duplicates(stack_a);
	//print_stack(*stack_a);
	return (*stack_a);
}
