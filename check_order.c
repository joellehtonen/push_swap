/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:54:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/10 11:12:00 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
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

	len = ft_lstsize(stack_a);
	target = 1;
	while (len != target)
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




// int	check_desc_order(t_stack *stack_b)
// {
// 	while (stack_b->next != NULL)
// 	{
// 		if (stack_b->content < stack_b->next->content)
// 			return (0);
// 		stack_b = stack_b->next;
// 	}
// 	return (1);
// }
