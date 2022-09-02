/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:29:45 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 19:30:09 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		size_t
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const size_t	src_len = ft_strlen(src);

	if (!dstsize)
		return (src_len);
	while (--dstsize && (*dst = *src))
	{
		++dst;
		++src;
	}
	if (!dstsize)
		*dst = '\0';
	return (src_len);
}
