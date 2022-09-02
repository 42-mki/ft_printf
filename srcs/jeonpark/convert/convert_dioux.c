/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dioux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:30:48 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:30:59 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "convert.h"
#include "t_spec.h"
#include "apply_option_dioux.h"
#include "libft.h"

/*
**	stdarg
**		va_arg()
*/

static int	convert_di(t_spec *spec)
{
	char				*buf_tmp;
	long long			ll;
	unsigned long long	ull;

	if (get_flag(spec, IS_LENGTH_LL))
		ll = va_arg(spec->ap, long long);
	else if (get_flag(spec, IS_LENGTH_L))
		ll = va_arg(spec->ap, long);
	else if (get_flag(spec, IS_LENGTH_HH))
		ll = (signed char)va_arg(spec->ap, int);
	else if (get_flag(spec, IS_LENGTH_H))
		ll = (short)va_arg(spec->ap, int);
	else
		ll = va_arg(spec->ap, int);
	if (ll < 0)
	{
		set_flag(spec, IS_NEGATIVE, TRUE);
		ull = -ll;
	}
	else
		ull = ll;
	if (!(buf_tmp = ft_ulltoa(ull)))
		return (-1);
	set_spec_buf(spec, buf_tmp, ft_strlen(buf_tmp), TRUE);
	return (0);
}

static int	convert_o(t_spec *spec)
{
	char				*buf_tmp;
	unsigned long long	ull;

	if (get_flag(spec, IS_LENGTH_LL))
		ull = va_arg(spec->ap, unsigned long long);
	else if (get_flag(spec, IS_LENGTH_L))
		ull = va_arg(spec->ap, unsigned long);
	else if (get_flag(spec, IS_LENGTH_HH))
		ull = (unsigned char)va_arg(spec->ap, unsigned int);
	else if (get_flag(spec, IS_LENGTH_H))
		ull = (unsigned short)va_arg(spec->ap, unsigned int);
	else
		ull = va_arg(spec->ap, unsigned int);
	if (!(buf_tmp = ft_ulltoo(ull)))
		return (-1);
	set_spec_buf(spec, buf_tmp, ft_strlen(buf_tmp), TRUE);
	return (0);
}

static int	convert_u(t_spec *spec)
{
	char				*buf_tmp;
	unsigned long long	ull;

	if (get_flag(spec, IS_LENGTH_LL))
		ull = va_arg(spec->ap, unsigned long long);
	else if (get_flag(spec, IS_LENGTH_L))
		ull = va_arg(spec->ap, unsigned long);
	else if (get_flag(spec, IS_LENGTH_HH))
		ull = (unsigned char)va_arg(spec->ap, unsigned int);
	else if (get_flag(spec, IS_LENGTH_H))
		ull = (unsigned short)va_arg(spec->ap, unsigned int);
	else
		ull = va_arg(spec->ap, unsigned int);
	if (!(buf_tmp = ft_ulltoa(ull)))
		return (-1);
	set_spec_buf(spec, buf_tmp, ft_strlen(buf_tmp), TRUE);
	return (0);
}

static int	convert_x(t_spec *spec)
{
	char				*buf_tmp;
	unsigned long long	ull;
	char				*ptr;

	if (get_flag(spec, IS_LENGTH_LL))
		ull = va_arg(spec->ap, unsigned long long);
	else if (get_flag(spec, IS_LENGTH_L))
		ull = va_arg(spec->ap, unsigned long);
	else if (get_flag(spec, IS_LENGTH_HH))
		ull = (unsigned char)va_arg(spec->ap, unsigned int);
	else if (get_flag(spec, IS_LENGTH_H))
		ull = (unsigned short)va_arg(spec->ap, unsigned int);
	else
		ull = va_arg(spec->ap, unsigned int);
	if (!(buf_tmp = ft_ulltox(ull)))
		return (-1);
	set_spec_buf(spec, buf_tmp, ft_strlen(buf_tmp), TRUE);
	if (*spec->pos_cur == 'X')
	{
		ptr = spec->buf;
		while ((*ptr = ft_toupper(*ptr)))
			++ptr;
	}
	return (0);
}

int			convert_dioux(t_spec *spec)
{
	char	ch;
	int		return_value;

	if (get_flag(spec, HAS_PRECISION))
		set_flag(spec, PAD_ZERO, FALSE);
	ch = *spec->pos_cur;
	return_value = 0;
	if (ch == 'd')
		return_value = convert_di(spec);
	else if (ch == 'i')
		return_value = convert_di(spec);
	else if (ch == 'o')
		return_value = convert_o(spec);
	else if (ch == 'u')
		return_value = convert_u(spec);
	else if (ch == 'x')
		return_value = convert_x(spec);
	else if (ch == 'X')
		return_value = convert_x(spec);
	if (return_value)
		return (-1);
	if (apply_option_dioux(spec))
		return (-1);
	return (0);
}
