/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:58:02 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:58:03 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		size_t
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;

	if (dst == src || !n)
		return (dst);
	ptr = dst;
	while (n)
	{
		*ptr++ = *(const unsigned char *)src++;
		--n;
	}
	return (dst);
}
