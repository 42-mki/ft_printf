/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:48:46 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:48:47 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		malloc(), size_t, NULL
*/

static char	*empty_str(void)
{
	char	*result;

	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	*result = '\0';
	return (result);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		s_len;
	char		*result;
	size_t		substr_len;

	if (!s || !len)
		return (empty_str());
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (empty_str());
	substr_len = ((s_len - start < len) ? s_len - start : len);
	if (!(result = malloc(substr_len + 1)))
		return (NULL);
	ft_memcpy(result, s + start, substr_len);
	*(result + substr_len) = '\0';
	return (result);
}
