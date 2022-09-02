/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chankim <chankim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:41:18 by chankim           #+#    #+#             */
/*   Updated: 2020/11/10 16:18:35 by chankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strndup(const char *str, size_t n)
{
	char *dest;

	if (!(dest = ft_calloc(sizeof(char), n + 1)))
		return (NULL);
	ft_memcpy(dest, str, n);
	return (dest);
}
