/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:49:55 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:49:56 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		malloc(), free(), NULL
*/

static void	*identity(void *x)
{
	return (x);
}

static void	nothing(void *x)
{
	(void)x;
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*p_result;
	void	*(*transform)(void *);
	void	(*delete_content)(void *);

	if (!lst)
		return (ft_lstnew(NULL));
	transform = f ? f : identity;
	delete_content = del ? del : nothing;
	if (!(result = ft_lstnew(transform(lst->content))))
		return (NULL);
	p_result = result;
	while ((lst = lst->next))
	{
		if (!(p_result->next = ft_lstnew(transform(lst->content))))
		{
			ft_lstclear(&result, delete_content);
			return (NULL);
		}
		p_result = p_result->next;
	}
	return (result);
}
