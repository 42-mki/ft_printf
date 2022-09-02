/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:24:55 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 19:24:59 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		NULL
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		++s;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
