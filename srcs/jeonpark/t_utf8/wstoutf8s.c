/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstoutf8s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:32:36 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:32:37 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "t_utf8.h"

/*
**	stdlib.h
**		malloc(), size_t
**
**	wchar.h
**		wchar_t
*/

static size_t	utf8_strlen_from_ws(const wchar_t *ws)
{
	size_t	len;

	len = 0;
	while (*ws)
	{
		len += 1
			+ ((*ws & TWO_BYTES_MASK) != 0)
			+ ((*ws & THREE_BYTES_MASK) != 0)
			+ ((*ws & FOUR_BYTES_MASK) != 0);
		++ws;
	}
	return (len);
}

char			*wstoutf8s(const wchar_t *ws)
{
	char	*utf8s;
	char	*ptr;
	t_utf8	utf8;

	if (!(utf8s = malloc(sizeof(utf8s) * (utf8_strlen_from_ws(ws) + 1))))
		return (0);
	ptr = utf8s;
	while (*ws)
	{
		utf8 = wctoutf8(*ws);
		cpyutf8tos(ptr, &utf8);
		ptr += utf8.len;
		++ws;
	}
	*ptr = '\0';
	return (utf8s);
}
