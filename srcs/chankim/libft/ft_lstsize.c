/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chankim <chankim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:47:02 by chankim           #+#    #+#             */
/*   Updated: 2020/10/09 18:12:34 by chankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		size;

	size = 0;
	curr = lst;
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}
