/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:11:36 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/09 13:01:45 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static	int	ft_minus(int64_t n)
{
	if (n < 0)
	{
		ft_putchar('-');
		return (1);
	}
	else
		return (0);
}

int			ft_putnbr_len(int64_t n, t_putnbr nbr)
{
	int	nbr_len;
	int	pad_len;
	int	ret;

	nbr_len = ft_nbrlen(n);
	if (n == 0 && nbr.precision == 0)
		nbr_len = 0;
	pad_len = nbr.width - ft_max(nbr_len, nbr.precision);
	pad_len = (pad_len < 0) ? 0 : pad_len;
	if (n < 0 && pad_len > 0)
		pad_len--;
	if (nbr.pad == '0')
		ret = ft_minus(n);
	if (!nbr.minus)
		ft_putchar_repeat(nbr.pad, pad_len);
	if (nbr.pad == ' ')
		ret = ft_minus(n);
	if (nbr_len != 0)
	{
		ft_putchar_repeat('0', nbr.precision - nbr_len);
		ft_putnbr(ft_abs(n));
	}
	if (nbr.minus)
		ft_putchar_repeat(nbr.pad, pad_len);
	return (ret + pad_len + ft_max(nbr_len, nbr.precision));
}
