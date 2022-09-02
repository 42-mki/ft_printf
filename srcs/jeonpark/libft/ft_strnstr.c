/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:34:29 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 19:35:00 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		size_t, NULL
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		haystack_len;
	size_t		needle_len;
	size_t		target_len;
	const char	*p_end;

	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	target_len = haystack_len < len ? haystack_len : len;
	p_end = haystack + target_len - needle_len;
	--haystack;
	while ((haystack = ft_strchr(haystack + 1, (int)*needle)))
	{
		if (p_end < haystack)
			return (NULL);
		if (!ft_memcmp(haystack, needle, needle_len))
			return ((char *)haystack);
	}
	return (NULL);
}
