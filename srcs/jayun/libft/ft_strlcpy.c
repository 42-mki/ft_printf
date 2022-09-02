/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 02:51:46 by jayun             #+#    #+#             */
/*   Updated: 2020/10/01 02:51:50 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	if (dst != 0 && src != 0)
	{
		if (dstsize > 0)
		{
			while (i < (int)(dstsize - 1) && src[i] != '\0')
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		i = 0;
		while (src[i] != '\0')
			i++;
	}
	return (i);
}
