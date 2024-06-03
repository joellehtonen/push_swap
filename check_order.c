/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:54:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/03 09:30:42 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
