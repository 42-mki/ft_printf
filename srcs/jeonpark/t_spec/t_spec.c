/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:31:57 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:31:59 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_spec.h"

/*
**	stdlib.h
**		NULL
*/

void	init_spec(t_spec *spec, const char *fmt)
{
	spec->pos_prev = fmt;
	spec->pos_cur = fmt;
	spec->flags = 0;
	set_spec_buf(spec, NULL, 0, FALSE);
	spec->num_of_char_printed = 0;
}

void	set_spec_buf(t_spec *spec, char *buf, size_t buf_len, int should_free)
{
	free_spec_buf(spec);
	spec->buf = buf;
	spec->buf_len = buf_len;
	set_flag(spec, SHOULD_FREE, should_free);
}

int		get_flag(t_spec *spec, int flag)
{
	return ((spec->flags & flag) != 0);
}

void	set_flag(t_spec *spec, int flag, int value)
{
	if (value)
		spec->flags |= flag;
	else
		spec->flags &= ~flag;
}

void	free_spec_buf(t_spec *spec)
{
	if (get_flag(spec, SHOULD_FREE))
		free(spec->buf);
}
