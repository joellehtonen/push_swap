/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:50:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/03 13:51:06 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**fill_stack(char **argv)
{
	int		i;
	int		number;
	t_list	*new;
	t_list	*stack_a;

	i = 0;
	number = 0;
	stack_a = NULL;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (NULL);
		new = ft_lstnew(number);
		if (!new)
		{
			ft_lstclear(stack_a, free_content);
			return (NULL);
		}
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (stack_a);
}
