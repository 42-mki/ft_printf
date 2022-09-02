/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:50:30 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/10 12:08:43 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

static int	ft_ifnull(t_format format)
{
	int	pad_len;
	int	str_len;

	str_len = ft_strlen(STR_NULL);
	pad_len = format.width - ft_min(str_len, format.precision);
	if (pad_len < 0)
		pad_len = 0;
	if (!ft_fminus(format))
		ft_putchar_repeat(' ', pad_len);
	ft_putnstr(STR_NULL, ft_min(str_len, format.precision));
	if (ft_fminus(format))
		ft_putchar_repeat(' ', pad_len);
	return (pad_len + ft_min(str_len, format.precision));
}

int			ft_sformat(t_format format, va_list ap)
{
	char	*arg;
	int		arg_len;

	arg = va_arg(ap, char*);
	arg_len = (arg == NULL) ? ft_strlen(STR_NULL) : ft_strlen(arg);
	if (format.precision == DEFAULT_PRECISION)
		format.precision = arg_len;
	arg_len = ft_min(format.precision, arg_len);
	if (arg == NULL)
		return (ft_ifnull(format));
	if (format.flag & FLAG_MINUS)
	{
		ft_putnstr(arg, arg_len);
		if (format.width > arg_len)
			ft_putchar_repeat(' ', format.width - arg_len);
	}
	else
	{
		if (format.width > arg_len)
			ft_putchar_repeat(' ', format.width - arg_len);
		ft_putnstr(arg, arg_len);
	}
	return (ft_max(arg_len, format.width));
}
