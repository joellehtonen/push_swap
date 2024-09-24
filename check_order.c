/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:54:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/09/05 15:32:58 by jlehtone         ###   ########.fr       */
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

void	assign_target_value(t_stack *stack_a)
{
	t_stack	*lowest;
	t_stack	*temp;
	int		len;
	int		target;

	len = ft_lstsize_int(stack_a);
	target = 1;
	while (target <= len)
	{
		lowest = NULL;
		temp = stack_a;
		while (temp)
		{
			if ((lowest == NULL || temp->content < lowest->content)
				&& (temp->target == 0))
				lowest = temp;
			temp = temp->next;
		}
		lowest->target = target;
		target++;
	}
}
