/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:30:42 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 19:30:43 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p_lst;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p_lst = *lst;
	while (p_lst->next)
		p_lst = p_lst->next;
	p_lst->next = new;
}
