/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:49:56 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/06 11:26:26 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(t_stack **stack_a, t_stack **stack_b, int error)
{
	if (*stack_a != NULL)
		ft_lstclear_int(stack_a);
	if (*stack_b != NULL)
		ft_lstclear_int(stack_b);
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	else
		exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!check_input(argv))
		free_and_exit(NULL, NULL, 1);
	stack_b = NULL;
	stack_a = fill_stack(argv);
	if (!stack_a)
		free_and_exit(&stack_a, NULL, 1);
	if (check_order(stack_a))
		return (1);
	sort_stack(&stack_a, &stack_b);
	free_and_exit(&stack_a, &stack_b, 0);
	return (1);
}
