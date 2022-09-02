/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:34:17 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:34:19 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		size_t
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;

	if (dst == src || !len)
		return (dst);
	if (dst < src)
	{
		p_dst = dst;
		while (len)
		{
			*p_dst++ = *(const unsigned char *)src++;
			--len;
		}
		return (dst);
	}
	p_dst = dst + len - 1;
	src += len - 1;
	while (len)
	{
		*p_dst-- = *(const unsigned char *)src--;
		--len;
	}
	return (dst);
}
