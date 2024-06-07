/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:16:06 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/07 13:58:18 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_median_of_three(t_stack *stack_a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*middle;
	int		mid_index;

	first = stack_a;
	last = ft_lstlast_int(stack_a);
	mid_index = ft_lstsize_int(stack_a) / 2;
	middle = stack_a;
	while (mid_index--)
		middle = middle->next;
	if ((first->content > middle->content) && (first->content < last->content))
		return (first);
	if ((middle->content > first->content) && (middle->content < last->content))
		return (middle);
	if ((last->content > first->content) && (last->content < middle->content))
		return (last);
}

void	quick_sort(t_stack **stack_a, t_stack **stack_b)
{
	int			pivot;
	t_stack		*check;

	if ((*stack_a == NULL) || (*stack_a)->next == NULL)
		return ;
	if (check_order(stack_a))
		return ;
	pivot = find_median_of_three(stack_a);
	check = *stack_a;
	while (check != NULL)
	{
		if ((check->content > pivot) && (check->content == (*stack_a)->content))
			ft_pb(stack_a, stack_b);
		else if ((check->content > pivot) && (check->content != (*stack_a)->content))
			ft_ra(stack_a);
		check = check->next;
	}
	quick_sort(stack_a, stack_b);
	quick_sort(stack_b, stack_a);
	while (*stack_b)
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
}
