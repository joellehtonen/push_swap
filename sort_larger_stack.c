/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_larger_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:13:31 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/12 16:40:43 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation_chooser(t_stack **sa, t_stack **sb, int index, int len)
{
	t_stack	*check;

	check = *sa;
	while (index-- > 1)
		check = check->next;
	if (check->cost_a != 0 && check->cost_b != 0)
	{
		if (index > len / 2)
			ft_rrr(sa, sb);
		else
			ft_rr(sa, sb);
		check->cost_a--;
		check->cost_b--;
	}
	else if (index > len / 2)
	{
		ft_rra(sa);
		check->cost_a--;
	}
	else
	{
		ft_ra(sa);
		check->cost_a--;
	}
}

void	node_to_right_place(t_stack **stack_b, int len)
{
	t_stack	*check;

	check = (*stack_b);
	while (check != NULL && check->cost_b > 0)
	{
		if (check->target + 1 == check->next->target)
			ft_sb(stack_b);
		else if (check->cost_b > len / 2)
			ft_rrb(stack_b);
		else
			ft_rb(stack_b);
		check->cost_b--;
	}
}

void	sort_larger_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		len;
	int		index;

	assign_target_value(*stack_a);
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	if (check_content_order(*stack_b))
		ft_sb(stack_b);
	len = ft_lstsize_int(*stack_a);
	while (len-- > 3)
	{
		assign_index(*stack_a);
		assign_cost(*stack_a, *stack_b);
		index = find_lowest_cost(*stack_a);
		while (index-- > 1)
			rotation_chooser(stack_a, stack_b, index, len);
		ft_pb(stack_a, stack_b);
		node_to_right_place(stack_b, len);
		if (check_content_order(*stack_a))
			break ;
	}
	sort_3(stack_a);
	final_push(stack_a, stack_b);
	if (!check_content_order(*stack_a))
		final_rotate(stack_a);
}
