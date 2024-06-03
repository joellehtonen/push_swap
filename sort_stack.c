/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:36:23 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/03 14:42:55 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_execute(t_list **stack_a, t_list **stack_b)
{
	int	pivot;

	if ((*stack_a == NULL) || (*stack_a)->next == NULL)
		return ;
	if (check_order(stack_a))
		return ;
	pivot = (*stack_a)->content;
	ft_pa(stack_a, stack_b);
	while (*stack_a != NULL)
	{
		if ((*stack_a)->content < pivot)
			ft_pa(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
}

void	quick_sort_initiate(t_list **stack_a, t_list **stack_b)
{
	quick_sort_execute(stack_a, stack_b);
	quick_sort_initiate(stack_a, stack_b);
	while (*stack_b != NULL)
		ft_pb(stack_b, stack_a);
}

void	sort_3(t_list *stack_a)
{
	
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(stack_a);
	if (len == 2)
		ft_sa(stack_a);
	else if (len == 3)
		sort_3(stack_a);
	else if (len > 3)
		quick_sort_initiate(stack_a, stack_b);
}
