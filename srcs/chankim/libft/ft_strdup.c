/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chankim <chankim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:20:44 by chankim           #+#    #+#             */
/*   Updated: 2020/10/26 17:54:01 by chankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(str);
	if (!(dest = ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	ft_memcpy(dest, str, len);
	return (dest);
}
