/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chankim <chankim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:29:34 by chankim           #+#    #+#             */
/*   Updated: 2020/10/30 21:36:47 by chankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*dest;

	s_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start > s_len)
		return (ft_strdup(""));
	if (len < 0)
		return (NULL);
	while (s[i + start] && i < len)
		i++;
	if (!(dest = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		dest[i] = s[i + start];
		i++;
	}
	return (dest);
}
