/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:36:23 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/06 15:57:32 by jlehtone         ###   ########.fr       */
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

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_lstsize_int(*stack_a);
	if (len == 2)
		ft_sa(stack_a);
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	else
		sorter(stack_a, stack_b);
}
