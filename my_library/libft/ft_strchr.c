/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:09:50 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:39:43 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = c;
	if (s == 0)
		return (0);
	while (*s != '\0' && *s != a)
	{
		s++;
	}
	if (*s == a)
		return ((char *)s);
	return (0);
}
