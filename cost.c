/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:10:06 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/01 10:53:44 by jlehtone         ###   ########.fr       */
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
		if ((stack_a->cost_a + stack_a->cost_b + stack_a->combo) < lowest_cost)
		{
			lowest_cost = (stack_a->cost_a + stack_a->cost_b + stack_a->combo);
			index = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	return (index);
}

int	find_cost(t_stack *stack, int ref)
{
	int		cost;
	int		next_index;

	cost = 0;
	assign_index(stack);
	next_index = find_next_smaller(stack, ref);
	cost = next_index - 1;
	return (cost);
}

void	combo_calc(t_stack *stack_a)
{
	stack_a->combo = 0;
	while (stack_a->cost_a > 0 && stack_a->cost_b > 0)
	{
		stack_a->cost_a--;
		stack_a->cost_b--;
		stack_a->combo++;
	}
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
		cost = find_cost(stack_b, stack_a->content);
		if (cost <= len_b / 2)
			stack_a->cost_b = cost;
		else
			stack_a->cost_b = len_b - cost;
		if (stack_a->index <= len_a / 2 + (len_a % 2))
			stack_a->cost_a = stack_a->index - 1;
		else
			stack_a->cost_a = len_a - stack_a->index + 1;
		ref = stack_a->index;
		if ((ref <= len_a / 2 + (len_a % 2) && first_half(stack_b, cost))
			|| (ref > len_a / 2 + (len_a % 2) && !first_half(stack_b, cost)))
			combo_calc(stack_a);
		stack_a = stack_a->next;
	}
}
