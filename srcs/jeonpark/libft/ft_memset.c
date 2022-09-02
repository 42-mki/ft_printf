/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:29:35 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:30:59 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		size_t
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	if (!len)
		return (b);
	ptr = b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}
