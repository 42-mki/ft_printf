/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:36:24 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 23:44:48 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_llsize_u(unsigned long long n)
{
	int count;

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

char		*ft_lltoa_u(unsigned long long n, int minus)
{
	char	*temp;
	int		size;

	size = get_llsize_u(n);
	if (minus == -1)
		size++;
	temp = (char *)malloc(sizeof(char) * (size + 1));
	if (temp == 0)
		return (0);
	temp[size] = '\0';
	if (n == 0 && minus == -1)
		temp[1] = '0';
	else if (n == 0)
		temp[0] = '0';
	if (minus == -1)
		temp[0] = '-';
	while (--size >= 0 && n != 0)
	{
		temp[size] = n % 10 * minus + '0';
		n /= 10;
	}
	return (temp);
}
