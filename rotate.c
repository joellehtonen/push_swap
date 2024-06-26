/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:04:24 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/26 13:35:42 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstrotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	tail = ft_lstlast_int(*stack);
	tail->next = temp;
	temp->next = NULL;
}

void	ft_ra(t_stack **stack_a)
{
	ft_lstrotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **stack_b)
{
	ft_lstrotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstrotate(stack_a);
	ft_lstrotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
