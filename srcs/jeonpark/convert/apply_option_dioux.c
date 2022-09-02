/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_dioux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:30:30 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:30:32 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "apply_option_dioux.h"
#include "t_spec.h"
#include "utils.h"
#include "libft.h"

/*
**	stdlib.h
**		malloc(), free(), size_t
*/

static int	apply_precision(t_spec *spec)
{
	size_t	padding_size;
	char	*buf_tmp;

	if (!get_flag(spec, HAS_PRECISION))
		return (0);
	if (!spec->precision && get_flag(spec, ZERO_VALUE))
	{
		*spec->buf = '\0';
		spec->buf_len = 0;
	}
	if (get_flag(spec, IS_HASH) && *spec->pos_cur == 'o'
			&& spec->precision <= spec->buf_len && *spec->buf != '0')
	{
		set_flag(spec, HAS_PRECISION, TRUE);
		spec->precision = spec->buf_len + 1;
	}
	if (spec->precision <= spec->buf_len)
		return (0);
	padding_size = spec->precision - spec->buf_len;
	if (!(buf_tmp = malloc(sizeof(*buf_tmp) * (spec->precision + 1))))
		return (-1);
	ft_memset(buf_tmp, '0', padding_size);
	ft_memcpy(buf_tmp + padding_size, spec->buf, spec->buf_len + 1);
	set_spec_buf(spec, buf_tmp, spec->precision, TRUE);
	return (0);
}

static void	apply_prefix(t_spec *spec, char **ptr)
{
	if (get_flag(spec, IS_NEGATIVE))
	{
		**ptr = '-';
		++*ptr;
	}
	else if (get_flag(spec, IS_PLUS))
	{
		**ptr = '+';
		++*ptr;
	}
	else if (get_flag(spec, IS_SPACE))
	{
		**ptr = ' ';
		++*ptr;
	}
	if (get_flag(spec, IS_HASH) && !get_flag(spec, ZERO_VALUE))
	{
		if (*spec->pos_cur == 'x' || *spec->pos_cur == 'X')
		{
			**ptr = '0';
			++*ptr;
			**ptr = *spec->pos_cur;
			++*ptr;
		}
	}
}

static int	apply_field_width2(t_spec *spec, size_t padding_size)
{
	char	*buf_tmp;
	char	*ptr;

	if (!(buf_tmp = malloc(sizeof(*buf_tmp) * (spec->field_width + 1))))
		return (-1);
	ptr = buf_tmp;
	if (!get_flag(spec, SHOULD_LEFT_ADJUSTMENT) && !get_flag(spec, PAD_ZERO))
		pad_char(&ptr, ' ', padding_size);
	apply_prefix(spec, &ptr);
	if (!get_flag(spec, SHOULD_LEFT_ADJUSTMENT) && get_flag(spec, PAD_ZERO))
		pad_char(&ptr, '0', padding_size);
	ft_memcpy(ptr, spec->buf, spec->buf_len);
	ptr += spec->buf_len;
	if (get_flag(spec, SHOULD_LEFT_ADJUSTMENT))
		pad_char(&ptr, ' ', padding_size);
	*ptr = '\0';
	set_spec_buf(spec, buf_tmp, spec->field_width, TRUE);
	return (0);
}

static int	apply_field_width(t_spec *spec)
{
	const char	ch = *spec->pos_cur;
	size_t		prefix_size;
	size_t		padding_size;

	prefix_size = (get_flag(spec, IS_SPACE)
			|| get_flag(spec, IS_NEGATIVE)
			|| get_flag(spec, IS_PLUS));
	prefix_size += !get_flag(spec, ZERO_VALUE)
		* get_flag(spec, IS_HASH)
		* (((ch == 'x') + (ch == 'X')) * 2);
	if (!(spec->buf_len + prefix_size <= spec->field_width))
	{
		if (prefix_size)
			spec->field_width = spec->buf_len + prefix_size;
		else
			return (0);
	}
	padding_size = spec->field_width - spec->buf_len - prefix_size;
	if (apply_field_width2(spec, padding_size))
		return (-1);
	return (0);
}

int			apply_option_dioux(t_spec *spec)
{
	if (*spec->buf == '0')
		set_flag(spec, ZERO_VALUE, TRUE);
	if (get_flag(spec, IS_HASH) && *spec->pos_cur == 'o')
		set_flag(spec, HAS_PRECISION, TRUE);
	if (apply_precision(spec))
		return (-1);
	if (apply_field_width(spec))
		return (-1);
	return (0);
}
