/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 02:52:32 by jayun             #+#    #+#             */
/*   Updated: 2020/10/12 20:26:30 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	n_len;

	i = 0;
	j = 0;
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)(haystack));
	while (haystack[i] && (unsigned long)i < len)
	{
		if (haystack[i] == needle[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		if (j == n_len)
			return ((char *)(haystack + i - j + 1));
		i++;
	}
	return (0);
}
