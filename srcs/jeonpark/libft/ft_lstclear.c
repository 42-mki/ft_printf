/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:00:36 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/05 09:38:41 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		free(), NULL
*/

static void	nothing(void *x)
{
	(void)x;
}

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	(*delete_content)(void *);
	t_list	*left_list;
	t_list	*right_list;

	if (!lst || !*lst)
		return ;
	delete_content = del ? del : nothing;
	left_list = *lst;
	right_list = left_list->next;
	delete_content(left_list->content);
	free(left_list);
	while (right_list)
	{
		left_list = right_list;
		right_list = left_list->next;
		delete_content(left_list->content);
		free(left_list);
	}
	*lst = NULL;
}
