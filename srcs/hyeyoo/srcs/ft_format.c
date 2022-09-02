/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 21:12:22 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/09 13:30:44 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "libftprintf.h"

int		ft_format(t_format format, va_list ap)
{
	if (format.specifier == 'c')
		return (ft_cformat(format, ap));
	else if (format.specifier == 's')
		return (ft_sformat(format, ap));
	else if (format.specifier == 'd')
		return (ft_dformat(format, ap));
	else if (format.specifier == 'i')
		return (ft_dformat(format, ap));
	else if (format.specifier == 'u')
		return (ft_uformat(format, ap));
	else if (format.specifier == 'p')
		return (ft_pformat(format, ap));
	else if (format.specifier == 'x')
		return (ft_xformat(format, ap));
	else if (format.specifier == 'X')
		return (ft_lxformat(format, ap));
	else if (format.specifier == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

void	ft_init_putnbr(t_putnbr *nbr)
{
	nbr->min_len = 0;
	nbr->pad = ' ';
	nbr->minus = 0;
	nbr->plus = 0;
	nbr->zero = 0;
	nbr->sharp = 0;
	nbr->space = 0;
	nbr->precision = DEFAULT_PRECISION;
	nbr->width = DEFAULT_WIDTH;
	nbr->base = NULL;
	nbr->prefix = NULL;
}
