/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:39:04 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/05 12:49:13 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstswap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	ft_sa(t_stack **stack_a)
{
	ft_lstswap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **stack_b)
{
	ft_lstswap(*stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstswap(*stack_a);
	ft_lstswap(*stack_b);
	ft_putstr_fd("ss\n", 1);
}
