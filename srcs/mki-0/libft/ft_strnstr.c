/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:41:59 by mki               #+#    #+#             */
/*   Updated: 2020/11/04 17:29:38 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strnstr(const char *haystack, char *needle, size_t n)
{
	size_t	len_needle;

	if (!*needle)
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	while (*haystack)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, len_needle))
			return ((char *)haystack);
		haystack++;
		if (len_needle >= n--)
			break ;
	}
	return (NULL);
}
