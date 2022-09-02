/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:18:31 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 13:43:25 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

/*
** ISSPACE(3)
**
** NAME
** isspace -- white-space character test
**
** SYNOPSIS
** #include <ctype.h>
**
** int
** isspace(int c);
**
** DESCRIPTION
** The isspace() function tests for the white-space characters.
** For any locale, this includes the following standard characters:
**
** ``\t''   ``\n''    ``\v''    ``\f''    ``\r''    `` ''
**
** In the "C" locale, isspace() successful test is limited to these
** characters only. The value of the argument must be representable as
** an unsigned char or the value of EOF.
**
** RETURN VALUES
** The isspace() function returns zero if the character tests false and
** returns non-zero if the character tests true.
*/

int	ptf_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' ||
			c == '\r' || c == '\t' || c == '\v');
}

/*
** ISDIGIT(3)
**
** NAME
** isdigit, isnumber -- decimal-digit character test
**
** SYNOPSIS
** #include <ctype.h>
**
** int	isdigit(int c);
**
** int	isnumber(int c);
**
** DESCRIPTION
** The isdigit() function tests for a decimal digit character.
** Regardless of locale, this includes the following characters only:
**
** ``0'' - ``9''
**
** The isnumber() function behaves similarly to isdigit(), but may recognize
** additional characters, depending on the current locale setting.
**
** The value of the argument must be representable as an unsigned char or
** the value of EOF.
**
** RETURN VALUES
** The isdigit() and isnumber() functions return zero if the character
** tests false and return non-zero if the character tests true.
*/

int	ptf_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

/*
** Check '%'
** long long v_63 = 0;
** v_63 |= (1LL << '%');
** 137438953472LL
**
** Check "XFGEcpdiuxnfgeo"
** long long v_127 = 0;
** v_127 |= ((1LL << ('X' - 64)) | (1LL << ('F' - 64)));
** v_127 |= ((1LL << ('G' - 64)) | (1LL << ('E' - 64)));
** v_127 |= ((1LL << ('c' - 64)) | (1LL << ('s' - 64)) | (1LL << ('p' - 64)));
** v_127 |= ((1LL << ('d' - 64)) | (1LL << ('i' - 64)) | (1LL << ('u' - 64)));
** v_127 |= ((1LL << ('x' - 64)) | (1LL << ('n' - 64)) | (1LL << ('f' - 64)));
** v_127 |= ((1LL << ('f' - 64)) | (1LL << ('g' - 64)) | (1LL << ('e' - 64)));
** v_127 |= (1LL << ('o' - 64));
** 83812438507520224LL
*/

int	ptf_istype(const char *c)
{
	if (*c <= 63)
		return ((137438953472LL & (1LL << ((long long)(*c)))) != 0LL);
	else if (*c <= 127)
		return ((83812438507520224LL &
			(1LL << ((long long)(*c) - 64LL))) != 0LL);
	else
		return (0);
}
