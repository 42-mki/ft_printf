/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chankim <chankim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:25:46 by chankim           #+#    #+#             */
/*   Updated: 2020/10/27 13:34:18 by chankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_size(char const *s, char c)
{
	size_t	cnt;

	cnt = 1;
	while (*s)
	{
		if (*s == c)
		{
			cnt++;
			s++;
		}
		else
			s++;
	}
	return (cnt);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*re;
	size_t	i;
	size_t	size;

	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * (cnt_size(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			re = (char *)s;
			while (*s && *s != c)
				s++;
			size = s - re + 1;
			if (!(ret[i] = (char *)malloc(size)))
				return (NULL);
			ft_strlcpy(ret[i++], re, size);
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}
