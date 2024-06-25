/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:30:12 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/25 16:06:40 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	int		index;

	index = 1;
	while (stack)
	{
		stack->index = index;
		stack = stack->next;
		index++;
	}
    return ;
}

int check_first_half(t_stack *stack, int ref)
{
	int	len;

	len = ft_lstsize_int(stack);
	if (ref <= len / 2 + (len % 2))
		return (1);
	else
		return (0);
}

int	find_next_bigger(t_stack *stack, int ref)
{
	t_stack	*check;
	t_stack	*bigger;
	t_stack *smallest;

	check = stack;
	bigger = NULL;
	smallest = NULL;
	while (check)
	{
		if (check->content > ref && (bigger == NULL || check->content < bigger->content))
			bigger = check;
		if (smallest == NULL || check->content < smallest->content)
            smallest = check;
		check = check->next;
	}
	if (bigger == NULL)
	{
		return (smallest->index);
	}
	return (bigger->index);
}

int	find_next_smaller(t_stack *stack, int ref)
{
	t_stack	*check;
	t_stack	*smaller;
	t_stack	*biggest;

	check = stack;
	smaller = NULL;
	biggest = NULL;
	while (check)
	{
		if (check->content < ref && (smaller == NULL || check->content > smaller->content))
			smaller = check;
		if (biggest == NULL || check->content > biggest->content)
			biggest = check;
		check = check->next;
	}
	if (smaller == NULL)
	{
		return (biggest->index);
	}
	return (smaller->index);
}
