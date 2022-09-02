/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:41:20 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:41:22 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		size_t, NULL
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	typedef unsigned char	t_raw;

	if (!n)
		return (NULL);
	while (--n && *(const t_raw *)s != (t_raw)c)
		++s;
	if (*(const t_raw *)s == (t_raw)c)
		return ((void *)s);
	return (NULL);
}
