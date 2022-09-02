/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:03:18 by mki               #+#    #+#             */
/*   Updated: 2020/11/04 17:31:40 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp_src;

	tmp_dst = dst;
	tmp_src = src;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (dst <= src)
		while (len--)
			*tmp_dst++ = *tmp_src++;
	else
	{
		tmp_dst += len;
		tmp_src += len;
		while (len--)
			*--tmp_dst = *--tmp_src;
	}
	return (dst);
}
