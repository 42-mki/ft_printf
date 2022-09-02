/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:30:31 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 20:08:45 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		size_t
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	src_len = ft_strlen(src);
	size_t			count;

	if (!dstsize)
		return (src_len);
	count = 0;
	while (++count != dstsize && *dst)
		++dst;
	if (*dst)
		return (dstsize + src_len);
	while ((*dst = *src) && count != dstsize)
	{
		++count;
		++dst;
		++src;
	}
	*dst = '\0';
	return (count - 1 + (*src ? ft_strlen(src) : 0));
}
