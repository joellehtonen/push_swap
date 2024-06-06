/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:37:11 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/06 11:25:01 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "library/libft/libft.h"
# include "library/printf/ft_printf.h"

typedef struct s_stack
{
 	int				content;
 	struct s_stack	*next;
}	t_stack;

void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_b, t_stack **stack_a);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	free_and_exit(t_stack **stack_a, t_stack **stack_b, int error);
void	ft_lstadd_back_int(t_stack **lst, t_stack *new);
void	ft_lstclear_int(t_stack **lst);
t_stack	*ft_lstnew_int(void *content);
int		ft_lstsize_int(t_stack *lst);
int		check_integer(char *argv);
int		check_min_max(char *argv);
int		check_duplicates(char **argv);
int		check_input(char **argv);
int		check_order(t_stack *stack_a);
t_stack	*fill_stack(char **argv);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

#endif