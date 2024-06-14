/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:50:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/07 14:00:22 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(char **argv)
{
	int		i;
	int		number;
	t_stack	*new;
	t_stack	*stack_a;

	i = 1;
	number = 0;
	stack_a = NULL;
	while (argv[i])
	{
		number = ft_atoll(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_and_exit(&stack_a, NULL, 1);
		new = ft_lstnew_int(number);
		if (!new)
		{
			ft_lstclear_int(&stack_a);
			return (NULL);
		}
		ft_lstadd_back_int(&stack_a, new);
		i++;
	}
	return (stack_a);
}
