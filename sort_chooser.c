/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chooser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:36:23 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/25 10:57:01 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	bottom = (*stack_a)->next->next->content;
	if ((top < middle) && (middle > bottom) && (bottom > top))
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if ((top > middle) && (middle < bottom) && (bottom > top))
		ft_sa(stack_a);
	else if ((top < middle) && (middle > bottom) && (bottom < top))
		ft_rra(stack_a);
	else if ((top > middle) && (middle < bottom) && (bottom < top))
		ft_ra(stack_a);
	else if ((top > middle) && (middle > bottom) && (bottom < top))
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	b_value;

	ft_pb(stack_a, stack_b);
	sort_3(stack_a);
	b_value = (*stack_b)->content;
	if (b_value < (*stack_a)->content)
		ft_pa(stack_b, stack_a);
	else if (b_value < (*stack_a)->next->content)
	{
		ft_pa(stack_b, stack_a);
		ft_sa(stack_a);
	}
	else if (b_value < (*stack_a)->next->next->content)
	{
		ft_rra(stack_a);
		ft_pa(stack_b, stack_a);
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else
	{
		ft_pa(stack_b, stack_a);
		ft_ra(stack_a);
	}
}

// void	sort_5(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		smallest;
// 	t_stack *check;	

// 	smallest = (*stack_a)->content;
// 	check = *stack_a;
// 	while (check)
// 	{
// 		if (check->content < smallest)
// 			smallest = check->content;
// 		check = check->next;
// 	}
// 	while ((*stack_a)->content != smallest)
// 	{
// 		if (check_first_half(*stack_a, smallest))
// 			ft_ra(stack_a);
// 		else
// 			ft_rra(stack_a);
// 	}
// 	ft_pb(stack_a, stack_b);
// 	sort_4(stack_a, stack_b);
// 	ft_pa(stack_b, stack_a);
// }

void	sort_chooser(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_lstsize_int(*stack_a);
	if (len == 2)
		ft_sa(stack_a);
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	//else if (len == 5)
	//	sort_5(stack_a, stack_b);
	else
		sort_larger_stack(stack_a, stack_b);
}
