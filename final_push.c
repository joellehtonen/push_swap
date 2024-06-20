/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:15:35 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/20 11:07:15 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_max_up(t_stack **stack_b)
{
	t_stack	*check;
	int		len;
	int		count;

	count = 0;
	if (check_content_order(*stack_b))
		return ;
	check = *stack_b;
	len = ft_lstsize_int(*stack_b);
	assign_index(*stack_b);
	while (check->next != NULL && check->target > check->next->target)
		check = check->next;
	if (check->next == NULL)
		return ;
	else
	{
		while (check->index != 0 && check->index != len)
		{
			if (check->index > len / 2)
			{
				ft_rrb(stack_b);
				check->index++;
				count++;
			}
			else
			{
				ft_rb(stack_b);
				check->index--;
				count++;
			}
		}
	}
}

void	final_rotate(t_stack **stack_a)
{
	t_stack	*check;
	int		len;

	if (check_content_order(*stack_a))
		return ;
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

	len_a = ft_lstsize_int(*stack_a);
	len_b = ft_lstsize_int(*stack_b);
	max = len_a + len_b;
	while (*stack_b)
	{
		if (((*stack_a)->target == (*stack_b)->target + 1) || (*stack_b)->target == max)
		{
			ft_pa(stack_b, stack_a);
			len_a++;
		}
		else
		{
			assign_index(*stack_a);
			target_index = find_next_bigger(*stack_a, (*stack_b)->content);
			while (target_index != 1 && target_index != len_a + 1)
			{
				if (target_index <= len_a / 2 + (len_a % 2))
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
	}
}
