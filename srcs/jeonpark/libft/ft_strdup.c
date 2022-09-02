/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:28:12 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:28:15 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		malloc(), size_t, NULL
*/

char	*ft_strdup(const char *s1)
{
	size_t	result_size;
	char	*result;
	char	*ptr;

	ptr = (char *)s1;
	while (*ptr)
		++ptr;
	result_size = ptr - (char *)s1 + 1;
	if (!(result = malloc(sizeof(*result) * result_size)))
		return (NULL);
	ptr = result;
	while (result_size)
	{
		*ptr++ = *s1++;
		--result_size;
	}
	return (result);
}
