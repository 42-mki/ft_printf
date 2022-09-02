/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:22:58 by jayun             #+#    #+#             */
/*   Updated: 2020/10/15 20:37:07 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_size(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char		*ft_itoa_u(unsigned int n)
{
	char	*temp;
	int		size;
	int		minus;

	size = get_size(n);
	minus = 1;
	if (n < 0)
		size++;
	if (n < 0)
		minus = -1;
	temp = (char *)malloc(sizeof(char) * (size + 1));
	if (temp == 0)
		return (0);
	temp[size] = '\0';
	if (n == 0)
		temp[0] = '0';
	if (n < 0)
		temp[0] = '-';
	while (--size >= 0 && n != 0)
	{
		temp[size] = n % 10 * minus + '0';
		n /= 10;
	}
	return (temp);
}
