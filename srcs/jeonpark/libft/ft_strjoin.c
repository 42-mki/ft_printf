/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:57:21 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:57:22 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		malloc(), size_t, NULL
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	char	*ptr;

	s1_len = s1 ? ft_strlen(s1) : 0;
	s2_len = s2 ? ft_strlen(s2) : 0;
	if (!(result = malloc(s1_len + s2_len + 1)))
		return (NULL);
	ptr = result;
	if (s1)
	{
		ft_memcpy(ptr, s1, s1_len);
		ptr += s1_len;
	}
	if (s2)
	{
		ft_memcpy(ptr, s2, s2_len);
		ptr += s2_len;
	}
	*ptr = '\0';
	return (result);
}
