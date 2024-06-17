/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:54:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/17 13:45:11 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_content_order(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_target_order(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->target > stack_a->next->target)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	assign_target_value(t_stack *stack_a)
{
	t_stack	*check;
	t_stack	*lowest;
	int		len;
	int		target;

	len = ft_lstsize_int(stack_a);
	target = 1;
	while (target <= len)
	{
		check = stack_a;
		lowest = NULL;
		while (check)
		{
			if ((lowest == NULL || check->content < lowest->content)
				&& (check->target == 0))
				lowest = check;
			check = check->next;
		}
		lowest->target = target;
		target++;
	}
}

// int	upper_lower(t_stack *stack)
// {
// 	t_stack *check;
// 	int 	len;

// 	check = stack;
// 	len = ft_lstsize_int(stack);

// }