/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:31:39 by mki               #+#    #+#             */
/*   Updated: 2020/11/07 16:08:36 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(long long n, int base_num, char *base)
{
	long long	tmp;
	char		c;

	tmp = (long long)n;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp *= -1;
	}
	c = base[tmp % base_num];
	if (tmp > base_num - 1)
		ft_putnbr_base(tmp / base_num, base_num, base);
	write(1, &c, 1);
}
