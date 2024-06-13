/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:10:06 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/13 16:02:30 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lowest_cost(t_stack *stack_a)
{
	int		lowest_cost;
	int		index;
	t_stack	*check;

	lowest_cost = (stack_a->cost_a + stack_a->cost_b);
	index = stack_a->index;
	check = stack_a;
	while (check)
	{
		if ((check->cost_a + check->cost_b) < lowest_cost)
		{
			lowest_cost = (check->cost_a + check->cost_b);
			index = check->index;
		}
		check = check->next;
	}
	return (index);
}

void	assign_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		cost;
	int		len_a;
	int		len_b;
	t_stack	*check;
	t_stack	*compare;

	check = stack_a;
	len_a = ft_lstsize_int(stack_a);
	len_b = ft_lstsize_int(stack_b);
	while (check)
	{
		cost = 0;
		compare = stack_b;
		while (compare != NULL && check->target < compare->target)
		{
			compare = compare->next;
			cost++;
		}
		if (cost <= len_b / 2)
			check->cost_b = cost;
		else
			check->cost_b = len_b - cost + 1;
		if (check->index <= len_a / 2)
			check->cost_a = check->index - 1;
		else
			check->cost_a = len_a - check->index + 1;
		check = check->next;
	}
}

void	assign_index(t_stack *stack)
{
	t_stack	*check;
	int		index;

	check = stack;
	index = 1;
	while (check)
	{
		check->index = index;
		check = check->next;
		index++;
	}
}
