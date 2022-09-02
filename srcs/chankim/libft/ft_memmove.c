/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chankim <chankim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:11:25 by chankim           #+#    #+#             */
/*   Updated: 2020/10/05 15:15:42 by chankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				index;
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (const unsigned char*)src;
	if (!dst && !src)
		return (NULL);
	index = 0;
	if (source < dest)
		while (index < len)
		{
			dest[len - index - 1] = source[len - index - 1];
			index++;
		}
	else
	{
		while (index < len)
		{
			dest[index] = source[index];
			index++;
		}
	}
	return (dst);
}
