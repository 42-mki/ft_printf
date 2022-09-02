/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 02:50:01 by jayun             #+#    #+#             */
/*   Updated: 2020/10/01 02:50:05 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_fd2(int n, int fd)
{
	char	c;
	int		minus;

	minus = 1;
	if (n < 0)
	{
		minus = -1;
		write(fd, "-", 1);
	}
	if (n != 0)
	{
		ft_putnbr_fd2(n / 10 * minus, fd);
		c = n % 10 * minus + '0';
		write(fd, &c, 1);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else
		ft_putnbr_fd2(n, fd);
}
