/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 06:05:28 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/09 13:04:54 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

static int	ft_ifnull(t_putnbr nbr)
{
	int	nbr_len;
	int	pad_len;

	nbr_len = ft_strlen(PTR_NULL);
	pad_len = nbr.width - ft_max(nbr_len, nbr.precision);
	if (pad_len < 0)
		pad_len = 0;
	if (!nbr.minus)
		ft_putchar_repeat(nbr.pad, pad_len);
	if (nbr_len != 0)
		ft_putstr(PTR_NULL);
	if (nbr.minus)
		ft_putchar_repeat(nbr.pad, pad_len);
	return (pad_len + ft_max(nbr_len, nbr.precision));
}

int			ft_pformat(t_format format, va_list ap)
{
	void		*arg;
	t_putnbr	nbr;

	ft_init_putnbr(&nbr);
	arg = va_arg(ap, void*);
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
	nbr.sharp = TRUE;
	nbr.prefix = "0x";
	nbr.base = "0123456789abcdef";
	if (arg == NULL)
		return (ft_ifnull(nbr));
	return (ft_putnbr_base_len((uint64_t)arg, nbr));
}
