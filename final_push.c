/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:15:35 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/12 17:03:36 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_value(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*check;

	check = stack_a;
	while (check->target != stack_b->target + 1)
		check = check->next;
	return (check->index);
}

void	final_rotate(t_stack **stack_a)
{
	t_stack	*check;
	int		len;

	check = *stack_a;
	len = ft_lstsize_int(*stack_a);
	assign_index(*stack_a);
	while (check->target != 1)
		check = check->next;
	while ((*stack_a)->target != 1)
	{
		if (check->index > len / 2)
			ft_rra(stack_a);
		else
			ft_ra(stack_a);
	}
}

void	final_push(t_stack **stack_a, t_stack **stack_b)
{
	int	target_index;
	int	len_a;
	int	len_b;
	int	max;

	len_a = 3;
	len_b = ft_lstsize_int(*stack_b);
	max = len_a + len_b;
	while (stack_b)
	{
		if (((*stack_a)->target == (*stack_b)->target + 1)
			|| (*stack_b)->target == max)
		{
			ft_pa(stack_b, stack_a);
			len_a++;
		}
		else
		{
			assign_index(*stack_a);
			target_index = find_target_value(*stack_a, *stack_b);
			while (target_index != 1 && target_index != len_a + 1)
			{
				if (target_index < len_a / 2)
				{
					ft_rra(stack_a);
					target_index++;
				}
				else
				{
					ft_ra(stack_a);
					target_index--;
				}
			}
		}
	}
}
