/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:06:01 by jlehtone          #+#    #+#             */
/*   Updated: 2024/04/26 16:36:46 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_content(void *content)
{
	free(content);
}

static void	capitalize_content(void *content)
{
	size_t	i;
	char	*result;

	result = (char *)content;
	i = 0;
	while (result[i])
	{
		result[i] = ft_toupper(result[i]);
		i++;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*result;

	if (!f || !lst || !del)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		result = f(lst->content);
		new_node = ft_lstnew(result);
		if (new_node == NULL)
		{
			del(result);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
