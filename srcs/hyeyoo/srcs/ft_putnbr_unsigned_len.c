/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_len.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:11:36 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/03/22 19:58:12 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int		ft_putnbr_unsigned_len(uint64_t n, t_putnbr nbr)
{
	int	nbr_len;
	int	pad_len;

	nbr_len = ft_nbrlen(n);
	if (n == 0 && nbr.precision == 0)
		nbr_len = 0;
	pad_len = nbr.width - ft_max(nbr_len, nbr.precision);
	if (pad_len < 0)
		pad_len = 0;
	if (!nbr.minus)
		ft_putchar_repeat(nbr.pad, pad_len);
	if (nbr_len != 0)
	{
		ft_putchar_repeat('0', nbr.precision - nbr_len);
		ft_putnbr(ft_abs(n));
	}
	if (nbr.minus)
		ft_putchar_repeat(nbr.pad, pad_len);
	return (pad_len + ft_max(nbr_len, nbr.precision));
}
