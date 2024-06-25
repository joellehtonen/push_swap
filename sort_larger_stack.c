/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_larger_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:13:31 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/25 12:09:29 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rotator(t_stack **sa, t_stack **sb, t_stack *check, int next_index)
{
	int first_half_a;
	int	first_half_b;

	first_half_a = check_first_half(*sa, check->index);
	first_half_b = check_first_half(*sb, next_index);
	while (check->cost_a > 0 && check->cost_b > 0)
	{
		if (first_half_a && first_half_b)
		{
			ft_rr(sa, sb);
			check->cost_a--;
			check->cost_b--;
		}
		else if (!first_half_a && !first_half_b)
		{
			ft_rrr(sa, sb);
			check->cost_a--;
			check->cost_b--;
		}
		else
			return ;
	}
}

void	rotate_a(t_stack **sa, t_stack **sb, int index)
{
	t_stack	*check;
	int		next_index;
	int		first_half;
	
	check = *sa;
	while (index-- > 1)
		check = check->next;
	next_index = find_next_smaller(*sb, check->content);
	//printf("chosen value is %d\n", check->content);
	//printf("its index is %d\n", check->index);
	//printf("its move cost is %d\n", check->cost_a + check->cost_b);
	double_rotator(sa, sb, check, next_index);
	first_half = check_first_half(*sa, check->index);
	while (check->cost_a > 0)
	{
		if (first_half)
			ft_ra(sa);
		else
			ft_rra(sa);
		check->cost_a--;
	}
}

void	node_to_right_place(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*check;
	int		next;
	int		ref;
	int		first_half;

	check = (*stack_a);
	ref = check->content;
	next = find_next_smaller(*stack_b, ref);
	first_half = check_first_half(*stack_b, next);
	while (check->cost_b > 0)
	{
		if (first_half)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
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
		assign_cost(*stack_a, *stack_b);
		index = find_lowest_cost(*stack_a);
		rotate_a(stack_a, stack_b, index);
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
