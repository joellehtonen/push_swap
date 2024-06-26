/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:42:54 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/26 17:26:35 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void command_chooser(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strncmp(cmd, "sa\n", 4) == 0)
        ft_lstswap(stack_a);
    else if (ft_strncmp(cmd, "sb\n", 4) == 0)
        ft_lstswap(stack_b);
    else if (ft_strncmp(cmd, "ss\n", 4) == 0)
    {
        ft_lstswap(stack_a);
        ft_lstswap(stack_b);
    }
    else if (ft_strncmp(cmd, "pa\n", 4) == 0)
        ft_lstpush(stack_b, stack_a);
    else if (ft_strncmp(cmd, "pb\n", 4) == 0)
        ft_lstpush(stack_a, stack_b);
    else if (ft_strncmp(cmd, "ra\n", 4) == 0)
        ft_lstrotate(stack_a);
    else if (ft_strncmp(cmd, "rb\n", 4) == 0)
        ft_lstrotate(stack_b);
    else if (ft_strncmp(cmd, "rr\n", 4) == 0)
    {
        ft_lstrotate(stack_a);
        ft_lstrotate(stack_b);
    }
    else if (ft_strncmp(cmd, "rra\n", 5) == 0)
        ft_lstreverse_rotate(stack_a);
    else if (ft_strncmp(cmd, "rrb\n", 5) == 0)
        ft_lstreverse_rotate(stack_b);
    else if (ft_strncmp(cmd, "rrr\n", 5) == 0)
    {
        ft_lstreverse_rotate(stack_a);
        ft_lstreverse_rotate(stack_b);
    }
    else
        free_and_exit(stack_a, stack_b, 1);
}

void checker(int argc, char **argv)
{
    char    *cmds;
    t_stack *stack_a;
    t_stack *stack_b;
    int     i;

    if (argc < 2)
		free_and_exit(NULL, NULL, 1);
    i = 0;
	stack_b = NULL;
	stack_a = NULL;
	stack_a = check_and_fill(argc, argv, &stack_a);
	if (!stack_a)
		free_and_exit(&stack_a, NULL, 0);
	if (check_content_order(stack_a))
		free_and_exit(&stack_a, NULL, 0);
    cmds = get_next_line(0);
    while (cmds[i])
    {
        command_chooser(&cmds[i], &stack_a, &stack_b);
        i++;
    }
    if (check_content_order(stack_a) && !(stack_b))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free_and_exit(&stack_a, &stack_b, 0);
}
