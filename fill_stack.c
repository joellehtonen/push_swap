/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:50:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/06 09:26:51 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(char **argv)
{
	int		i;
	int		number;
	t_stack	*new;
	t_stack	*stack_a;

	i = 0;
	number = 0;
	stack_a = NULL;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (NULL);
		new = ft_lstnew_int(number);
		if (!new)
		{
			ft_lstclear_int(stack_a);
			return (NULL);
		}
		ft_lstadd_back_int(stack_a, new);
		i++;
	}
	return (stack_a);
}
