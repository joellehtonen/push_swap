/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:37:11 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/19 11:59:58 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "library/libft/libft.h"
# include "library/printf/ft_printf.h"
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	int				target;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

//operations
void		ft_sa(t_stack **stack_a);
void		ft_sb(t_stack **stack_b);
void		ft_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack_b, t_stack **stack_a);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		ft_ra(t_stack **stack_a);
void		ft_rb(t_stack **stack_b);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rra(t_stack **stack_a);
void		ft_rrb(t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);
//list_int functions
void		ft_lstadd_back_int(t_stack **lst, t_stack *new);
void		ft_lstclear_int(t_stack **lst);
t_stack		*ft_lstlast_int(t_stack *lst);
t_stack		*ft_lstnew_int(int content);
int			ft_lstsize_int(t_stack *lst);
//checker functions
int			check_integer(char *argv);
int			check_duplicates(char **argv);
int			check_input(char **argv);
int			check_content_order(t_stack *stack_a);
int			check_target_order(t_stack *stack_a);
void		check_min_max(t_stack **stack_a, long long number);
long long	ft_atoll(const char *str);
void		free_and_exit(t_stack **stack_a, t_stack **stack_b, int error);
//initialization, costs, targets, indexes
t_stack		*fill_stack(int argc, char **argv, t_stack **stack_a);
char		**check_argument(int argc, char **argv);
void		assign_target_value(t_stack *stack_a);
int			find_lowest_cost(t_stack *stack_a);
int			find_next_smaller(t_stack *stack_b, int ref);
int			find_next_bigger(t_stack *stack_b, int ref);
int			find_cost_b(t_stack *stack_b, int ref);
void		assign_cost(t_stack *stack_a, t_stack *stack_b);
void		assign_index(t_stack *stack);
int			find_target_value(t_stack *stack_a, t_stack *stack_b);
//sorting functions
void		sort_chooser(t_stack **stack_a, t_stack **stack_b);
void		sort_3(t_stack **stack_a);
void		sort_4(t_stack **stack_a, t_stack **stack_b);
void		sort_larger_stack(t_stack **stack_a, t_stack **stack_b);
void		rotate_a_b(t_stack **sa, t_stack **sb, int index, int len);
void		node_to_right_place(t_stack **stack_a, t_stack **stack_b);
void		rotate_max_up(t_stack **stack_b);
void		final_rotate(t_stack **stack_a);
void		final_push(t_stack **stack_a, t_stack **stack_b);
void		print_stack(t_stack *stack_a);

#endif