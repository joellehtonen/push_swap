/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:37:11 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/13 16:05:19 by jlehtone         ###   ########.fr       */
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

long long	ft_atoll(const char *str);
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
void		free_and_exit(t_stack **stack_a, t_stack **stack_b, int error);
void		ft_lstadd_back_int(t_stack **lst, t_stack *new);
void		ft_lstclear_int(t_stack **lst);
t_stack		*ft_lstlast_int(t_stack *lst);
t_stack		*ft_lstnew_int(int content);
int			ft_lstsize_int(t_stack *lst);
int			check_integer(char *argv);
int			check_min_max(char *argv);
int			check_duplicates(char **argv);
int			check_input(char **argv);
int			check_content_order(t_stack *stack_a);
int			check_target_order(t_stack *stack_a);
void		assign_target_value(t_stack *stack_a);
int			find_lowest_cost(t_stack *stack_a);
void		assign_cost(t_stack *stack_a, t_stack *stack_b);
void		assign_index(t_stack *stack);
int			find_target_value(t_stack *stack_a, t_stack *stack_b);
void		final_rotate(t_stack **stack_a);
void		rotate_max_up(t_stack **stack_b);
void		final_push(t_stack **stack_a, t_stack **stack_b);
t_stack		*fill_stack(char **argv);
void		sort_3(t_stack **stack_a);
void		sort_4(t_stack **stack_a, t_stack **stack_b);
void		sort_chooser(t_stack **stack_a, t_stack **stack_b);
void		rotation_chooser(t_stack **sa, t_stack **sb, int index, int len);
int			find_next(t_stack *stack_b);
void		node_to_right_place(t_stack **stack_b, int len);
void		sort_larger_stack(t_stack **stack_a, t_stack **stack_b);
void		print_stack(t_stack *stack_a);


#endif