/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:35:24 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/20 15:28:43 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		malloc(), NULL
*/

static char	identity(unsigned int x, char y)
{
	(void)x;
	return (y);
}

static char	*empty_str(void)
{
	char	*result;

	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	*result = '\0';
	return (result);
}

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	char			*p_result;
	unsigned int	index;
	char			(*transform)(unsigned int, char);

	if (!s)
		return (empty_str());
	transform = f ? f : identity;
	if (!(result = malloc(ft_strlen(s) + 1)))
		return (NULL);
	p_result = result;
	index = 0;
	while (*s && (*p_result++ = f(index, *s)))
	{
		++index;
		++s;
	}
	*p_result = '\0';
	return (result);
}
