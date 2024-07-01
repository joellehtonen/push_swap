/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:42:44 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/01 14:10:18 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(t_stack **stack_a, t_stack **stack_b, int error)
{
	if (stack_a && *stack_a)
		ft_lstclear_int(stack_a);
	if (stack_b && *stack_b)
		ft_lstclear_int(stack_b);
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
		exit(0);
}

void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	print_stack(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp)
	{
		printf("%d ", temp->content);
		temp = temp->next;
	}
	printf("\n");
}
