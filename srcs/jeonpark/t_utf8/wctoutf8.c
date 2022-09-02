/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wctoutf8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:32:27 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:32:32 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "libft.h"
#include "t_utf8.h"

/*
**	stdlib.h
**		malloc(), NULL
**
**	wchar.h
**		wchar_t
*/

/*
**	1 byte
**	0000 0000  0000 0000  0000 0000
**	0000 0000  0000 0000  0111 1111
**	-> 0xxx xxxx
**
**	2 byte
**	0000 0000  0000 0000  1000 0000
**	0000 0000  0000 0111  1111 1111
**	-> 110x xxxx  10xx xxxx
**
**	3 byte
**	0000 0000  0000 1000  0000 0000
**	0000 0000  1111 1111  1111 1111
**	-> 1110 xxxx  10xx xxxx  10xx xxxx
**
**	4 byte
**	0000 0001  0000 0000  0000 0000
**	0001 0000  1111 1111  1111 1111
**	-> 1111 0xxx  10xx xxxx  10xx xxxx  10xx xxxx
*/

static t_utf8	encode_1(wchar_t wc)
{
	t_utf8	utf8;

	utf8.data = (unsigned int)wc;
	utf8.len = 1;
	return (utf8);
}

static t_utf8	encode_2(wchar_t wc)
{
	t_utf8	utf8;

	utf8.data = 0xc080;
	utf8.data |= (wc & 0x1f << 6) << 2;
	utf8.data |= wc & 0x3f;
	utf8.len = 2;
	return (utf8);
}

static t_utf8	encode_3(wchar_t wc)
{
	t_utf8	utf8;

	utf8.data = 0xe08080;
	utf8.data |= (wc & 0xf << 12) << 4;
	utf8.data |= (wc & 0x3f << 6) << 2;
	utf8.data |= wc & 0x3f;
	utf8.len = 3;
	return (utf8);
}

static t_utf8	encode_4(wchar_t wc)
{
	t_utf8	utf8;

	utf8.data = 0xf0808080;
	utf8.data |= (wc & 0x7 << 18) << 6;
	utf8.data |= (wc & 0x3f << 12) << 4;
	utf8.data |= (wc & 0x3f << 6) << 2;
	utf8.data |= wc & 0x3f;
	utf8.len = 4;
	return (utf8);
}

t_utf8			wctoutf8(wchar_t wc)
{
	if (wc & FOUR_BYTES_MASK)
		return (encode_4(wc));
	else if (wc & THREE_BYTES_MASK)
		return (encode_3(wc));
	else if (wc & TWO_BYTES_MASK)
		return (encode_2(wc));
	else
		return (encode_1(wc));
}
