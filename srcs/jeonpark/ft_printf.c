/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:29:53 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:29:54 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"
#include "t_spec.h"
#include "convert.h"

/*
**	stdlib.h
**		free(), NULL
**
**	unistd.h
**		write()
**
**	stdarg.h
**		va_start(), va_end()
**
**	limits.h
**		INT_MAX
*/

static int	print_plain(t_spec *spec)
{
	const size_t	size_to_print = spec->pos_cur - spec->pos_prev;

	if (!((size_t)spec->num_of_char_printed + size_to_print < (size_t)INT_MAX))
		return (-1);
	write(1, spec->pos_prev, size_to_print);
	spec->num_of_char_printed += size_to_print;
	return (0);
}

static int	set_spec(t_spec *spec)
{
	char	ch;
	int		return_value;

	read_spec(spec);
	ch = *spec->pos_cur;
	if (ch == 'd'
			|| ch == 'i'
			|| ch == 'o'
			|| ch == 'u'
			|| ch == 'x'
			|| ch == 'X')
		return_value = convert_dioux(spec);
	else if (ch == 'c')
		return_value = convert_c(spec);
	else if (ch == 's')
		return_value = convert_s(spec);
	else if (ch == 'p')
		return_value = convert_p(spec);
	else if (ch == 'n')
		return_value = convert_n(spec);
	else if (ch == '%')
		return_value = convert_percent(spec);
	else
		return_value = -1;
	return (return_value);
}

static int	print_spec(t_spec *spec)
{
	if (!(spec->buf_len < (size_t)(INT_MAX - spec->num_of_char_printed)))
		return (-1);
	write(1, spec->buf, spec->buf_len);
	++(spec->pos_cur);
	spec->num_of_char_printed += spec->buf_len;
	set_spec_buf(spec, NULL, 0, FALSE);
	return (0);
}

static int	real_ft_printf(t_spec *spec)
{
	while (*spec->pos_cur)
	{
		if (*spec->pos_cur == '%')
		{
			if (print_plain(spec)
					|| set_spec(spec)
					|| print_spec(spec))
			{
				free_spec_buf(spec);
				return (-1);
			}
			spec->pos_prev = spec->pos_cur;
		}
		else
			++(spec->pos_cur);
	}
	if (print_plain(spec))
		return (-1);
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	t_spec	spec;

	init_spec(&spec, fmt);
	va_start(spec.ap, fmt);
	if (real_ft_printf(&spec))
		return (-1);
	va_end(spec.ap);
	return (spec.num_of_char_printed);
}
