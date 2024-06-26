/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:04:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/26 13:35:58 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstreverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*new_tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = ft_lstlast_int(*stack);
	new_tail = *stack;
	while (new_tail->next->next != NULL)
		new_tail = new_tail->next;
	new_tail->next = NULL;
	head->next = *stack;
	*stack = head;
}

void	ft_rra(t_stack **stack_a)
{
	ft_lstreverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_lstreverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstreverse_rotate(stack_a);
	ft_lstreverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
