/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:04:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/05 12:48:23 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstreverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*new_tail;

	head = ft_lstlast(*stack);
	new_tail = *stack;
	while (new_tail->next->next != NULL)
		new_tail = new_tail->next;
	new_tail->next = NULL;
	head->next = *stack;
	*stack = head;
}

void	ft_rra(t_stack **stack_a)
{
	ft_lstrotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_lstrotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstrotate(stack_a);
	ft_lstrotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
