/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:31:37 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 19:31:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		malloc(), NULL
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
