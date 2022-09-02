/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:23:06 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/09 13:05:29 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

static int	ft_cformat_none(t_format format, va_list ap)
{
	unsigned char	arg;
	char			pad;

	arg = (unsigned char)va_arg(ap, int);
	pad = (format.flag & FLAG_ZERO) ? '0' : ' ';
	if (format.flag & FLAG_MINUS)
	{
		ft_putchar(arg);
		ft_putchar_repeat(pad, format.width - 1);
	}
	else
	{
		ft_putchar_repeat(pad, format.width - 1);
		ft_putchar(arg);
	}
	return (ft_max(1, format.width));
}

int			ft_cformat(t_format format, va_list ap)
{
	return (ft_cformat_none(format, ap));
}
