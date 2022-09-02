/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:31:36 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:31:37 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include "t_spec.h"
#include "libft.h"

/*
**	stddef.h
**		size_t
**
**	stdarg.h
**		va_arg()
*/

static void	read_flag(t_spec *spec)
{
	char	ch;

	ch = *spec->pos_cur;
	while (ch == '0'
			|| ch == '-'
			|| ch == '#'
			|| ch == ' '
			|| ch == '+')
	{
		if (ch == '0')
			set_flag(spec, PAD_ZERO, TRUE);
		else if (ch == '-')
			set_flag(spec, SHOULD_LEFT_ADJUSTMENT, TRUE);
		else if (ch == '#')
			set_flag(spec, IS_HASH, TRUE);
		else if (ch == ' ')
			set_flag(spec, IS_SPACE, TRUE);
		else if (ch == '+')
		{
			set_flag(spec, IS_PLUS, TRUE);
			set_flag(spec, IS_SPACE, FALSE);
		}
		++(spec->pos_cur);
		ch = *spec->pos_cur;
	}
}

static void	read_field_width(t_spec *spec)
{
	int	i;

	if (*spec->pos_cur == '*')
	{
		i = va_arg(spec->ap, int);
		++(spec->pos_cur);
		if (i > 0)
			spec->field_width = (size_t)i;
		else
		{
			spec->field_width = (size_t)-i;
			set_flag(spec, SHOULD_LEFT_ADJUSTMENT, TRUE);
		}
	}
	else
		spec->field_width = (size_t)ft_atoi(spec->pos_cur);
	while (ft_isdigit(*spec->pos_cur))
		++(spec->pos_cur);
}

static void	read_precision(t_spec *spec)
{
	int	i;

	if (!(*spec->pos_cur == '.'))
		return ;
	++(spec->pos_cur);
	if (*spec->pos_cur == '*')
	{
		i = va_arg(spec->ap, int);
		++(spec->pos_cur);
	}
	else
		i = ft_atoi(spec->pos_cur);
	if (i >= 0)
	{
		set_flag(spec, HAS_PRECISION, TRUE);
		spec->precision = i;
	}
	if (*spec->pos_cur == '-')
		++(spec->pos_cur);
	while (ft_isdigit(*spec->pos_cur))
		++(spec->pos_cur);
}

static void	read_length_modifier(t_spec *spec)
{
	while (*spec->pos_cur == 'h' || *spec->pos_cur == 'l')
	{
		if (*spec->pos_cur == 'h')
		{
			set_flag(spec, IS_LENGTH_HH, get_flag(spec, IS_LENGTH_H));
			set_flag(spec, IS_LENGTH_H, TRUE);
		}
		else if (*spec->pos_cur == 'l')
		{
			set_flag(spec, IS_LENGTH_LL, get_flag(spec, IS_LENGTH_L));
			set_flag(spec, IS_LENGTH_L, TRUE);
		}
		++(spec->pos_cur);
	}
}

void		read_spec(t_spec *spec)
{
	++(spec->pos_cur);
	spec->flags = 0;
	read_flag(spec);
	read_field_width(spec);
	read_precision(spec);
	read_length_modifier(spec);
}
