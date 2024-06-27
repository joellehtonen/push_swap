/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:10:06 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/27 14:59:57 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lowest_cost(t_stack *stack_a)
{
	int		lowest_cost;
	int		index;

	lowest_cost = INT_MAX;
	index = 0;
	while (stack_a)
	{
		if ((stack_a->cost_a + stack_a->cost_b) < lowest_cost)
		{
			lowest_cost = (stack_a->cost_a + stack_a->cost_b);
			index = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	return (index);
}

int	find_cost_b(t_stack *stack_b, int ref)
{
	int		cost;
	int		next_index;

	cost = 0;
	assign_index(stack_b);
	next_index = find_next_smaller(stack_b, ref);
	cost = next_index - 1;
	return (cost);
}

void	assign_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		cost;
	int		len_a;
	int		len_b;
	int		ref;

	cost = 0;
	len_b = ft_lstsize_int(stack_b);
	len_a = ft_lstsize_int(stack_a);
	while (stack_a)
	{
		ref = stack_a->content;
		cost = find_cost_b(stack_b, ref);
		if (cost <= len_b / 2)
			stack_a->cost_b = cost;
		else
			stack_a->cost_b = len_b - cost;
		if (stack_a->index <= len_a / 2 + (len_a % 2))
			stack_a->cost_a = stack_a->index - 1;
		else
			stack_a->cost_a = len_a - stack_a->index + 1;
		//printf("assigned cost_a of %d and cost_b of %d to the content of %d\n", stack_a->cost_a, stack_a->cost_b, stack_a->content);
		stack_a = stack_a->next;
	}
}
