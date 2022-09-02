/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:27:09 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 19:27:47 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		size_t
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	typedef unsigned char	t_raw;

	if (!n)
		return (0);
	while (--n && *(const t_raw *)s1 == *(const t_raw *)s2)
	{
		++s1;
		++s2;
	}
	return ((int)(*(const t_raw *)s1 - *(const t_raw *)s2));
}
