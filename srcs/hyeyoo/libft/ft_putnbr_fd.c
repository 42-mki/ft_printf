/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:11:36 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/03/16 21:48:07 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

void	ft_putnbr_fd(int64_t n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n / 10 != 0)
			ft_putnbr_fd(-(n / 10), fd);
		ft_putchar_fd(-(n % 10) + '0', fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
