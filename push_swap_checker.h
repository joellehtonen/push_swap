/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:37:27 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/26 17:26:39 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "push_swap.h"
# include "library/libft/libft.h"
# include "library/get_next_line/get_next_line.h"

void command_chooser(char *cmd, t_stack **stack_a, t_stack **stack_b);
void checker(int argc, char **argv);

#endif