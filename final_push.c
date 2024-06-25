/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:15:35 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/25 12:13:21 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_max_up(t_stack **stack_b)
{
	int	len;
	int	first_half;
	t_stack	*check;
	
	if (check_content_order(*stack_b))
		return ;
	check = *stack_b;
	len = ft_lstsize_int(*stack_b);
	assign_index(*stack_b);
	while (check->next != NULL && check->target > check->next->target)
		check = check->next;
	first_half = check_first_half(*stack_b, (*stack_b)->index);
	while (check->index != 0 && check->index != len)
	{
		if (first_half)
		{
			ft_rb(stack_b);
			check->index--;
		}
		else
		{
			ft_rrb(stack_b);
			check->index++;
		}
	}
}

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

void	other_target(t_stack **stack_a, t_stack **stack_b, int len_a)
{
	int	target_index;
	int	first_half;

	assign_index(*stack_a);
	target_index = find_next_bigger(*stack_a, (*stack_b)->content);
	first_half = check_first_half(*stack_a, target_index);
	while (target_index != 1 && target_index != len_a + 1)
	{
		if (first_half)
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
	int	len_b;
	int	max;
	int flag;

	len_a = ft_lstsize_int(*stack_a);
	len_b = ft_lstsize_int(*stack_b);
	flag = 0;
	max = len_a + len_b;
	if (check_content_order(*stack_b))
		ft_sb(stack_b);
	while (*stack_b)
	{
		if (((*stack_a)->target == (*stack_b)->target + 1) || (*stack_b)->target == max || flag == 1)
		{
			ft_pa(stack_b, stack_a);
			len_a++;
			flag = 0;
			//print_stack(*stack_a);
		}
		else
		{
			other_target(stack_a, stack_b, len_a);
			flag = 1;
		}
	}
}
