/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:02:36 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/25 13:18:06 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_int(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new || !lst)
		return ;
	if ((*lst) == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_lstclear_int(t_stack **lst)
{
	if (!lst || !(*lst))
		return ;
	ft_lstclear_int(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}

t_stack	*ft_lstlast_int(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstnew_int(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->target = 0;
	new->index = 0;
	new->next = NULL;
	new->cost_a = 0;
	new->cost_b = 0;
	new->moveable = 1;
	return (new);
}

int	ft_lstsize_int(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
