/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:04:21 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/06 10:27:55 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstpush(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*temp;

	if (*stack_src == NULL)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = *stack_dst;
	*stack_dst = temp;
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_lstpush(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstpush(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
