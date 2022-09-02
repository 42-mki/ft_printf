/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:02:32 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 20:07:48 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
**	unistd.h
**		write()
*/

#define MAX_INT_LEN 10

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	positive_n;
	char			tmp[MAX_INT_LEN + 1];
	char			*p_tmp;

	positive_n = (n < 0 ? -n : n);
	p_tmp = tmp + MAX_INT_LEN;
	*p_tmp = '0' + positive_n % 10;
	while ((positive_n /= 10))
		*(--p_tmp) = '0' + positive_n % 10;
	if (n < 0)
		*(--p_tmp) = '-';
	write(fd, p_tmp, MAX_INT_LEN - (p_tmp - tmp) + 1);
}
