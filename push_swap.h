/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:37:11 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/03 14:15:20 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "library/libft/libft.h"
# include "library/printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_b, t_list **stack_a);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	free_and_exit(t_list **stack_a, t_list **stack_b, int error);
int		check_integer(char *argv);
int		check_duplicates(char **argv);
int		check_input(char **argv);
int		check_order(t_list *stack_a);
t_list	**fill_stack(char **argv);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	quick_sort_initiate(t_list **stack_a, t_list **stack_b);
void	quick_sort_execute(t_list **stack_a, t_list **stack_b);

#endif