/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:30:45 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:30:46 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <wchar.h>
#include "convert.h"
#include "t_spec.h"
#include "t_utf8.h"
#include "libft.h"

/*
**	stdlib.h
**		malloc(), free(), size_t
**
**	stdarg
**		va_arg()
**
**	wchar.h
**		wchar_t, wint_t
*/

static int	apply_option(t_spec *spec)
{
	size_t	padding_size;
	char	*buf_tmp;

	if (!(spec->buf_len < spec->field_width))
		return (0);
	padding_size = spec->field_width - spec->buf_len;
	if (!(buf_tmp = malloc(sizeof(*buf_tmp) * (spec->field_width + 1))))
		return (-1);
	if (get_flag(spec, SHOULD_LEFT_ADJUSTMENT))
	{
		ft_memcpy(buf_tmp, spec->buf, spec->buf_len);
		ft_memset(buf_tmp + spec->buf_len, ' ', padding_size);
	}
	else
	{
		ft_memset(buf_tmp, get_flag(spec, PAD_ZERO) ? '0' : ' ', padding_size);
		ft_memcpy(buf_tmp + padding_size, spec->buf, spec->buf_len);
	}
	*(buf_tmp + spec->field_width) = '\0';
	set_spec_buf(spec, buf_tmp, spec->field_width, TRUE);
	return (0);
}

int			convert_c(t_spec *spec)
{
	char	*buf_tmp;
	t_utf8	utf8;
	char	c;

	if (get_flag(spec, IS_LENGTH_L))
	{
		utf8 = wctoutf8((wchar_t)va_arg(spec->ap, wint_t));
		if (!(buf_tmp = malloc(sizeof(*spec->buf) * (utf8.len + 1))))
			return (-1);
		cpyutf8tos(buf_tmp, &utf8);
		buf_tmp[utf8.len] = '\0';
		set_spec_buf(spec, buf_tmp, utf8.len, TRUE);
	}
	else
	{
		c = (char)va_arg(spec->ap, int);
		if (!(buf_tmp = malloc(sizeof(*spec->buf) * 2)))
			return (-1);
		buf_tmp[0] = c;
		buf_tmp[1] = '\0';
		set_spec_buf(spec, buf_tmp, 1, TRUE);
	}
	if (apply_option(spec))
		return (-1);
	return (0);
}
