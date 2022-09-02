/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chankim <chankim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:43:47 by chankim           #+#    #+#             */
/*   Updated: 2020/10/19 14:51:16 by chankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *result;

	if (!(result = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
