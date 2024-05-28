/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:04:21 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/28 11:59:05 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstpush_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp

	if (*stack_a == NULL)
		return ;
	//stack_a_len--;
	//stack_b_len++;
	ft_putstr_fd("pa\n", 1);
}
