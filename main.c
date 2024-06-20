/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:49:56 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/20 14:18:11 by jlehtone         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	stack_a = fill_stack(argc, argv, &stack_a);
	if (!stack_a)
		free_and_exit(&stack_a, NULL, 0);
	if (check_content_order(stack_a))
		free_and_exit(&stack_a, NULL, 0);
	sort_chooser(&stack_a, &stack_b);
	print_stack(stack_a);
	free_and_exit(&stack_a, &stack_b, 0);
	return (1);
}
