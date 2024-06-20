/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_larger_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:13:31 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/20 10:04:33 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_b(t_stack **sa, t_stack **sb, int index, int len_a)
{
	t_stack	*check;
	int		len_b;
	int		next_index;

	check = *sa;
	while (index-- > 1)
		check = check->next;
	len_b = ft_lstsize_int(*sb);
	next_index = find_next_smaller(*sb, check->content);
	while (check->cost_a > 0 && check->cost_b > 0)
	{
		if (check->index > len_a / 2 && next_index > len_b / 2)
		{
			ft_rrr(sa, sb);
			check->cost_a--;
			check->cost_b--;
		}
		else if (check->index < len_a / 2 && next_index < len_b / 2)
		{
			ft_rr(sa, sb);
			check->cost_a--;
			check->cost_b--;
		}
		else
			break ;
	}
	while (check->cost_a > 0)
	{
		if (check->index > len_a / 2)
			ft_rra(sa);
		else
			ft_ra(sa);
		check->cost_a--;
	}
}

void	node_to_right_place(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*check;
	int		next;
	int		ref;
	int		len;

	check = (*stack_a);
	ref = check->content;
	len = ft_lstsize_int(*stack_b);
	next = find_next_smaller(*stack_b, ref);
	while (check->cost_b > 0)
	{
		if (next > len / 2 + (len % 2))
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
	len = ft_lstsize_int(*stack_a);
	while (len > 3)
	{
		assign_index(*stack_a);
		//longest_desc_order(*stack_a);
		assign_cost(*stack_a, *stack_b);
		index = find_lowest_cost(*stack_a);
		rotate_a_b(stack_a, stack_b, index, len);
		node_to_right_place(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		//print_stack(*stack_b);
		len--;
		if (check_content_order(*stack_a))
			break ;
	}
	sort_3(stack_a);
	rotate_max_up(stack_b);
	final_push(stack_a, stack_b);
	//print_stack(*stack_a);
	final_rotate(stack_a);
}
