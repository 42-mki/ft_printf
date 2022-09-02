/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 02:51:26 by jayun             #+#    #+#             */
/*   Updated: 2020/10/02 18:06:16 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		dst_len;
	int		src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if ((unsigned long)(dst_len + 1) < dstsize)
	{
		while (src[i] != '\0' && (unsigned long)(i + dst_len + 1) < dstsize)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	if (dstsize < (unsigned long)dst_len)
		return (dstsize + src_len);
	return (dst_len + src_len);
}
