/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_larger_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:13:31 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/14 16:24:06 by jlehtone         ###   ########.fr       */
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
	next_index = find_next(*sb, check->content);
	//printf("chosen value is %d\n", check->content);
	//printf("its index is %d\n", check->index);
	if (check->cost_a > 0 && check->cost_b > 0)
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
	}
	if (check->cost_a > 0)
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
	next = find_next(*stack_b, ref);
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
	if (check_content_order(*stack_b))
		ft_sb(stack_b);
	len = ft_lstsize_int(*stack_a);
	while (len > 3)
	{
		assign_index(*stack_a);
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
	final_rotate(stack_a);
}
