/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:50:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/17 16:29:03 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_arg(int argc, char **argv)
{
	char		**splitted;
	long long	result;
	int			i;

	i = 1;
	if (argc == 2)
		splitted = ft_split(argv[1], " ");
	result = ft_atoll(splitted[i]);
		if (result > INT_MAX || result < INT_MIN)
			free_and_exit(&argv, NULL, 1);
}

t_stack	*fill_stack(int argc, char **argv)
{
	int		i;
	t_stack	*new;
	t_stack	*stack_a;

	i = 1;
	stack_a = NULL;
	while (argv[i])
	{
		new = ft_lstnew_int(argv[i]);
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
