/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpyutf8tos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:32:25 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:32:26 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_utf8.h"

/*
**	stdlib.h
**		NULL, size_t
*/

char	*cpyutf8tos(char *des, t_utf8 *src)
{
	size_t	index;

	if (!(des && src))
		return (NULL);
	index = 0;
	while (index < src->len)
	{
		des[index] = src->data >> 8 * (src->len - index - 1) & 0xff;
		++index;
	}
	return (des);
}
