/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:21:51 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/01 14:09:00 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_content(void *content)
{
	free(content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
