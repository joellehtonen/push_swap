/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:49:56 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/01 11:13:16 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	stack_a = check_and_fill(argc, argv, &stack_a);
	if (!stack_a)
		free_and_exit(&stack_a, NULL, 0);
	if (check_content_order(stack_a))
		free_and_exit(&stack_a, NULL, 0);
	sort_chooser(&stack_a, &stack_b);
	free_and_exit(&stack_a, &stack_b, 0);
	return (1);
}
