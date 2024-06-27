/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:42:54 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/27 17:28:52 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./library/get_next_line/get_next_line.h"

int command_reverse_rotate(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strncmp(cmd, "rra\n", 5) == 0)
    {
        ft_lstreverse_rotate(stack_a);
        return (1);
    }
    else if (ft_strncmp(cmd, "rrb\n", 5) == 0)
    {
        ft_lstreverse_rotate(stack_b);
        return (1);
    }
    else if (ft_strncmp(cmd, "rrr\n", 5) == 0)
    {
        ft_lstreverse_rotate(stack_a);
        ft_lstreverse_rotate(stack_b);
        return (1);
    }
    else
        return (0);
}

int command_rotate(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strncmp(cmd, "ra\n", 4) == 0)
    {
        ft_lstrotate(stack_a);
        return (1);
    }
    else if (ft_strncmp(cmd, "rb\n", 4) == 0)
    {
        ft_lstrotate(stack_b);
        return (1);
    }
    else if (ft_strncmp(cmd, "rr\n", 4) == 0)
    {
        ft_lstrotate(stack_a);
        ft_lstrotate(stack_b);
        return (1);
    }
    else
    {
        if (!command_reverse_rotate(cmd, stack_a, stack_b))
            return (0);
        else
            return (1);
    }
}

int command_push(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strncmp(cmd, "pa\n", 4) == 0)
    {
        ft_lstpush(stack_b, stack_a);
        return (1);
    }
    else if (ft_strncmp(cmd, "pb\n", 4) == 0)
    {
        ft_lstpush(stack_a, stack_b);
        return (1);
    }
    else
    {
        if (!command_rotate(cmd, stack_a, stack_b))
            return (0);
        else
            return (1);
    }
}

int command_swap(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strncmp(cmd, "sa\n", 4) == 0)
    {
        ft_lstswap(stack_a);
        return (1);
    }
    else if (ft_strncmp(cmd, "sb\n", 4) == 0)
    {
        ft_lstswap(stack_b);
        return (1);
    }
    else if (ft_strncmp(cmd, "ss\n", 4) == 0)
    {
        ft_lstswap(stack_a);
        ft_lstswap(stack_b);
        return (1);
    }
    else
    {
        if (!command_push(cmd, stack_a, stack_b))
            return (0);
        else
            return (1);
    }
}

int main(int argc, char **argv)
{
    char    *cmds;
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	stack_a = check_and_fill(argc, argv, &stack_a);
	if (!stack_a)
		free_and_exit(&stack_a, NULL, 0);
    while ((cmds = get_next_line(0)) != NULL)
    {
        if (!command_swap(cmds, &stack_a, &stack_b))
        {
            free(cmds);
            free_and_exit(&stack_a, &stack_b, 1);
        }
        free(cmds);
    }
    if (check_content_order(stack_a) && stack_b == NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free_and_exit(&stack_a, &stack_b, 0);
}
