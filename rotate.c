/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:04:24 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/28 11:06:51 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstrotate(t_list **stack)
{
	t_list	*temp;
	t_list	*tail;

	temp = *stack;
	*stack = (*stack)->next;
	tail = ft_lstlast(*stack);
	tail->next = temp;
	temp->next = NULL;
}

void	ft_ra(t_list **stack_a)
{
	ft_lstrotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_list **stack_b)
{
	ft_lstrotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_lstrotate(stack_a);
	ft_lstrotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
