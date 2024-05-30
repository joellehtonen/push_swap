/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:04:21 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/30 15:52:55 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstpush(t_list **stack_1, t_list **stack_2)
{
	t_list	*temp_1;

	if (*stack_1 == NULL)
		return ;
	temp_1 = *stack_1;
	*stack_1 = (*stack_1)->next;
	temp_1->next = *stack_2;
	*stack_2 = temp_1;
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	ft_lstpush(stack_a, stack_b);
	ft_putstr_fd("sa\n", 1);
}

void	ft_pb(t_list **stack_b, t_list **stack_a)
{
	ft_lstpush(stack_b, stack_a);
	ft_putstr_fd("sb\n", 1);
}
