/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:10:06 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/20 11:11:56 by jlehtone         ###   ########.fr       */
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

int	find_next_bigger(t_stack *stack_b, int ref)
{
	t_stack	*check;
	t_stack	*bigger;
	t_stack *smallest;

	check = stack_b;
	bigger = NULL;
	smallest = NULL;
	while (check)
	{
		if (check->content > ref && (bigger == NULL || check->content < bigger->content))
			bigger = check;
		if (smallest == NULL || check->content > smallest->content)
            smallest = check;
		check = check->next;
	}
	if (bigger == NULL)
		return (smallest->index);
	return (bigger->index);
}

int	find_next_smaller(t_stack *stack, int ref)
{
	t_stack	*check;
	t_stack	*smaller;
	t_stack	*biggest;

	check = stack;
	smaller = NULL;
	biggest = NULL;
	while (check)
	{
		if (check->content < ref && (smaller == NULL || check->content > smaller->content))
			smaller = check;
		if (biggest == NULL || check->content > biggest->content)
			biggest = check;
		check = check->next;
	}
	if (smaller == NULL)
		return (biggest->index);
	return (smaller->index);
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
	t_stack	*check;

	cost = 0;
	check = stack_a;
	len_b = ft_lstsize_int(stack_b);
	len_a = ft_lstsize_int(stack_a);
	while (check)
	{
		ref = check->content;
		cost = find_cost_b(stack_b, ref);
		if (cost <= len_b / 2)
			check->cost_b = cost;
		else
			check->cost_b = len_b - cost;
		if (check->index <= len_a / 2)
			check->cost_a = check->index - 1;
		else
			check->cost_a = len_a - check->index + 1;
		check = check->next;
	}
}
