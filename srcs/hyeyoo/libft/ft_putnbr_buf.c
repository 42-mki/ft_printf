/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:11:36 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/03/16 21:54:09 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

static void	ft_putnbr_buf_sub(int64_t n, char *buf, size_t *i)
{
	if (n < 0)
	{
		buf[(*i)++] = '-';
		if (n / 10 != 0)
			ft_putnbr_buf_sub(-(n / 10), buf, i);
		buf[(*i)++] = -(n % 10) + '0';
	}
	else
	{
		if (n >= 10)
			ft_putnbr_buf_sub(n / 10, buf, i);
		buf[(*i)++] = n % 10 + '0';
	}
}

void		ft_putnbr_buf(int64_t n, char *buf, size_t *i)
{
	ft_putnbr_buf_sub(n, buf, i);
	buf[(*i)++] = '\0';
}
