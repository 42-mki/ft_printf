/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:47:31 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 20:09:03 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		malloc(), NULL, size_t
*/

static int	ft_str_contains_char(char const *str, char c)
{
	while (*str && *str != c)
		++str;
	return (*str && *str == c);
}

static char	*empty_str(void)
{
	char	*result;

	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	*result = '\0';
	return (result);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char const	*p_end;
	char		*result;
	size_t		result_len;

	if (!s1)
		return (empty_str());
	if (!set)
		return (ft_strdup(s1));
	while (ft_str_contains_char(set, *s1))
		++s1;
	if (!*s1)
		return (empty_str());
	p_end = s1;
	while (*p_end)
		++p_end;
	while (ft_str_contains_char(set, *(--p_end)))
		;
	result_len = p_end - s1 + 1;
	if (!(result = malloc(result_len + 1)))
		return (NULL);
	ft_memcpy(result, s1, result_len);
	*(result + result_len) = '\0';
	return (result);
}
