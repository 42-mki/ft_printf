/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_spec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:31:52 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:31:53 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SPEC_H
# define T_SPEC_H

# include <stddef.h>
# include <stdarg.h>

/*
**	stddef.h
**		size_t
**
**	stdarg.h
**		va_list
*/

# define PAD_ZERO				0x00000001
# define SHOULD_LEFT_ADJUSTMENT	0x00000002
# define IS_NEGATIVE			0x00000004
# define HAS_PRECISION			0x00000008
# define SHOULD_FREE			0x00000010
# define IS_LENGTH_H			0x00000020
# define IS_LENGTH_HH			0x00000040
# define IS_LENGTH_L			0x00000080
# define IS_LENGTH_LL			0x00000100
# define IS_HASH				0x00000200
# define IS_SPACE				0x00000400
# define IS_PLUS				0x00000800
# define HAS_PREFIX				0x00001000
# define ZERO_VALUE				0x00002000

# define TRUE	1
# define FALSE	0

typedef struct	s_spec
{
	const char	*pos_prev;
	const char	*pos_cur;
	va_list		ap;
	int			flags;
	size_t		field_width;
	size_t		precision;
	char		*buf;
	size_t		buf_len;
	int			num_of_char_printed;
}				t_spec;

void			init_spec(t_spec *spec, const char *fmt);
void			set_spec_buf(
		t_spec *spec, char *buf, size_t buf_len, int should_free);
int				get_flag(t_spec *spec, int index);
void			set_flag(t_spec *spec, int index, int value);
void			free_spec_buf(t_spec *spec);
void			read_spec(t_spec *spec);

#endif
