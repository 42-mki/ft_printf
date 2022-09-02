/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:43:18 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/09 13:09:44 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int	ft_dformat(t_format format, va_list ap)
{
	int			arg;
	t_putnbr	nbr;

	ft_init_putnbr(&nbr);
	arg = va_arg(ap, int);
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
	return (ft_putnbr_len((int)arg, nbr));
}
