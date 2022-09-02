/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 06:05:28 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/09 13:10:41 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int	ft_xformat(t_format format, va_list ap)
{
	unsigned int	arg;
	t_putnbr		nbr;

	ft_init_putnbr(&nbr);
	arg = va_arg(ap, unsigned int);
	nbr.minus = (ft_fminus(format));
	nbr.minus = (ft_fspace(format)) ? FALSE : nbr.minus;
	nbr.plus = ft_fplus(format);
	if (!nbr.minus && format.precision == DEFAULT_PRECISION && ft_fzero(format))
		nbr.pad = '0';
	else
		nbr.pad = ' ';
	nbr.space = ft_fspace(format);
	nbr.precision = format.precision;
	nbr.width = format.width;
	nbr.sharp = ft_fsharp(format);
	nbr.prefix = "0x";
	nbr.base = "0123456789abcdef";
	return (ft_putnbr_base_len(arg, nbr));
}
