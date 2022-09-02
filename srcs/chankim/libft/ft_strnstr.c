/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chankim <chankim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:13:32 by chankim           #+#    #+#             */
/*   Updated: 2020/10/19 18:42:39 by chankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*little == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (1)
	{
		if (little[j] == '\0')
			return ((char *)(big + (i - j)));
		if (big[i] == little[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		if (big[i] == '\0' | i >= len)
			return (NULL);
		i++;
	}
}
