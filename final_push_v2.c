/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:15:35 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/28 11:44:05 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_stack **stack_a)
{
	t_stack	*check;
	int		first_half;

	if (check_content_order(*stack_a))
		return ;
	check = *stack_a;
	assign_index(*stack_a);
	while (check->target != 1)
		check = check->next;
	first_half = check_first_half(*stack_a, check->index);
	while ((*stack_a)->target != 1)
	{
		if (first_half)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

void	rotate_b_final(t_stack **sa, t_stack **sb, int index)
{
	t_stack	*check;
	int		next_index;
	int		first_half;

	check = *sb;
	while (index-- > 1)
		check = check->next;
	next_index = find_next_bigger(*sa, check->content);
	double_rotate(sa, sb, check, next_index);
	first_half = check_first_half(*sb, check->index);
	while (check->cost_b > 0)
	{
		if (first_half)
			ft_rb(sb);
		else
			ft_rrb(sb);
		check->cost_b--;
	}
}

void	rotate_a_final(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*check;
	int		next;
	int		ref;
	int		first_half;

	check = (*stack_b);
	ref = check->content;
	next = find_next_bigger(*stack_a, ref);
	first_half = check_first_half(*stack_a, next);
	while (check->cost_a > 0)
	{
		if (first_half)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
		check->cost_a--;
	}
}

void	final_push_v2(t_stack **stack_a, t_stack **stack_b)
{
	int		index;

	while (stack_b)
	{
		assign_index(*stack_b);
		assign_cost(*stack_b, *stack_a);
		index = find_lowest_cost(*stack_b);
		rotate_b_final(stack_a, stack_b, index);
		rotate_a_final(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
}
