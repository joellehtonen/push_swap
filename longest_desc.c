/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_desc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:57:19 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/19 16:25:16 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_moveable_zero(t_stack *start, int longest)
{
    while (longest > 0)
    {
        start->moveable = 0;
        start = start->next;
        longest--;
    }
}

void    longest_desc_order(t_stack *stack_a)
{
	int	    now;
	int	    longest;
	t_stack *start;

	start = NULL;
	longest = 0;
	while (stack_a)
	{
		now = 1;
		while (stack_a->next != NULL && stack_a->content < stack_a->next->content)
		{
			now++;
			stack_a = stack_a->next;
		}
		if (now > longest)
		{
			longest = now;
			start = stack_a;
		}
		stack_a = stack_a->next;
	}
    set_moveable_zero(start, longest);
}
