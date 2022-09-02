/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 06:09:08 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/09 13:11:50 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "libftprintf.h"

int		ft_putnbr_base_len(uint64_t n, t_putnbr nbr)
{
	int	nbr_len;
	int	pad_len;
	int	ret;

	ret = 0;
	nbr_len = (n == 0 && nbr.precision == 0) ? 0 : ft_nbrlen_base(n, 16);
	pad_len = nbr.width - ft_max(nbr_len, nbr.precision);
	if (nbr.sharp)
	{
		pad_len -= 2;
		ret = 2;
	}
	pad_len = (pad_len < 0) ? 0 : pad_len;
	if (!nbr.minus)
		ft_putchar_repeat(nbr.pad, pad_len);
	if (nbr_len != 0)
	{
		if (nbr.sharp)
			ft_putstr(nbr.prefix);
		ft_putchar_repeat('0', nbr.precision - nbr_len);
		ft_putnbr_base(ft_abs(n), nbr.base);
	}
	if (nbr.minus)
		ft_putchar_repeat(nbr.pad, pad_len);
	return (ret + pad_len + ft_max(nbr_len, nbr.precision));
}
