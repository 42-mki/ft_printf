/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:54:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/08 16:49:39 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		malloc(), free(), size_t, NULL
*/

static void	*empty_mem(size_t size)
{
	void	*result;

	if (!(result = malloc(size)))
		return (NULL);
	ft_bzero(result, size);
	return (result);
}

static int	word_count(char const *str, char c)
{
	int	count;

	if (!c)
		return (*str ? 1 : 0);
	count = (*str == c ? -1 : 0);
	while (*str)
	{
		++count;
		while (*str != c && *str)
			++str;
		while (*str == c)
			++str;
	}
	return (count);
}

static char	*new_word(char const *str, char c)
{
	char		*word;
	char const	*p_str;
	size_t		word_len;

	p_str = str;
	while (*p_str && *p_str != c)
		++p_str;
	word_len = p_str - str;
	if (!(word = malloc(sizeof(*word) * (word_len + 1))))
		return (NULL);
	ft_memcpy(word, str, word_len);
	*(word + word_len) = '\0';
	return (word);
}

static void	*delete_result(char **start, char **end)
{
	while (start != end)
		free(*(--end));
	free(start);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		result_size;
	char	**result;
	char	**pp_result;

	if (!s)
		return (empty_mem(sizeof(*result)));
	result_size = word_count(s, c) + 1;
	if (!(result = malloc(sizeof(*result) * result_size)))
		return (NULL);
	pp_result = result;
	if (*s && *s != c && --result_size)
		if (!(*pp_result++ = new_word(s, c)))
			return (delete_result(result, pp_result));
	while (--result_size)
	{
		while (*s && *s != c)
			++s;
		while (*s == c)
			++s;
		if (!(*pp_result++ = new_word(s, c)))
			return (delete_result(result, pp_result));
	}
	*pp_result = NULL;
	return (result);
}
