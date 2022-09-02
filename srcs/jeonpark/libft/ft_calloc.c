/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:23:30 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:23:34 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		malloc(), size_t, NULL
*/

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	unsigned char	*p_result;

	if (!(result = malloc(count * size)))
		return (NULL);
	p_result = result + count * size;
	while (result != p_result)
		*(--p_result) = 0;
	return (result);
}
