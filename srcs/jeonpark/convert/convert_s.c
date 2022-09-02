/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:31:15 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:31:16 by jeonpark         ###   ########.fr       */
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
**		wchar_t
*/

static int	apply_precision(t_spec *spec)
{
	char	*buf_tmp;
	char	*ptr;
	size_t	buf_len;

	if (!get_flag(spec, HAS_PRECISION))
		return (0);
	if (!(spec->precision < spec->buf_len))
		return (0);
	if (get_flag(spec, IS_LENGTH_L))
	{
		ptr = spec->buf + spec->precision;
		while ((*ptr & 0x80) && !(*ptr & 0x40))
			--ptr;
		buf_len = ptr - spec->buf;
	}
	else
		buf_len = spec->precision;
	if (!(buf_tmp = malloc(sizeof(*buf_tmp) * (buf_len + 1))))
		return (-1);
	ft_memcpy(buf_tmp, spec->buf, buf_len);
	buf_tmp[buf_len] = '\0';
	set_spec_buf(spec, buf_tmp, buf_len, TRUE);
	return (0);
}

static int	apply_field_width(t_spec *spec)
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

static int	apply_option(t_spec *spec)
{
	if (apply_precision(spec))
		return (-1);
	if (apply_field_width(spec))
		return (-1);
	return (0);
}

int			convert_s(t_spec *spec)
{
	char			*buf_tmp;
	const wchar_t	*ws;

	if (get_flag(spec, IS_LENGTH_L))
	{
		ws = va_arg(spec->ap, wchar_t *);
		if (!ws)
			set_spec_buf(spec, "(null)", 6, FALSE);
		else
		{
			if (!(buf_tmp = wstoutf8s(ws)))
				return (-1);
			set_spec_buf(spec, buf_tmp, ft_strlen(buf_tmp), TRUE);
		}
	}
	else
	{
		buf_tmp = va_arg(spec->ap, char *);
		if (!buf_tmp)
			set_spec_buf(spec, "(null)", 6, FALSE);
		else
			set_spec_buf(spec, buf_tmp, ft_strlen(buf_tmp), FALSE);
	}
	return (apply_option(spec));
}
