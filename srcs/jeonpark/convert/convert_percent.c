/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:31:09 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:31:10 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "convert.h"
#include "t_spec.h"
#include "libft.h"

/*
**	stdlib.h
**		malloc(), free(), size_t
**
**	stdarg
**		va_arg()
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

int			convert_percent(t_spec *spec)
{
	char	*buf_tmp;

	if (!(buf_tmp = malloc(sizeof(*spec->buf) * 2)))
		return (-1);
	*buf_tmp = '%';
	set_spec_buf(spec, buf_tmp, 1, TRUE);
	if (apply_option(spec))
		return (-1);
	return (0);
}
