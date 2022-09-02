/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:58:51 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:59:24 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		size_t, NULL
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	typedef unsigned char	t_raw;

	if (!n)
		return (NULL);
	while ((*(t_raw *)dst = *(const t_raw *)src) != (t_raw)c && --n)
	{
		++dst;
		++src;
	}
	if (*(t_raw *)dst == (t_raw)c)
		return (dst + 1);
	return (NULL);
}
