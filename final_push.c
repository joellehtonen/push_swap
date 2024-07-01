/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:15:35 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/01 10:09:19 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_stack **stack_a)
{
	t_stack	*check;

	if (check_content_order(*stack_a))
		return ;
	check = *stack_a;
	assign_index(*stack_a);
	while (check->target != 1)
		check = check->next;
	while ((*stack_a)->target != 1)
	{
		if (first_half(*stack_a, check->index))
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

void	other_target(t_stack **stack_a, t_stack **stack_b, int len_a)
{
	int	target_index;

	assign_index(*stack_a);
	target_index = find_next_bigger(*stack_a, (*stack_b)->content);
	while (target_index != 1 && target_index != len_a + 1)
	{
		if (first_half(*stack_a, target_index))
		{
			ft_ra(stack_a);
			target_index--;
		}
		else
		{
			ft_rra(stack_a);
			target_index++;
		}
	}
}

void	final_push(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	int	flag;

	len_a = ft_lstsize_int(*stack_a);
	flag = 0;
	while (*stack_b)
	{
		if (((*stack_a)->target == (*stack_b)->target + 1) || flag == 1)
		{
			ft_pa(stack_b, stack_a);
			len_a++;
			flag = 0;
		}
		else
		{
			other_target(stack_a, stack_b, len_a);
			flag = 1;
		}
	}
}
