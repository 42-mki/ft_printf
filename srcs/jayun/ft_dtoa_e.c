/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:49:10 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 21:03:17 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_lltoa_e2(long long n, int minus, int size, char **temp)
{
	if (n == 0)
	{
		(*temp)[0] = '0';
		(*temp)[1] = '.';
	}
	if (minus == -1)
		(*temp)[0] = '-';
	while (--size >= 0 && n != 0)
	{
		if (size == 2 && minus == -1)
			(*temp)[2] = '.';
		else if (size == 1 && minus == 1)
			(*temp)[1] = '.';
		else
		{
			(*temp)[size] = n % 10 * minus + '0';
			n /= 10;
		}
	}
}

static char	*ft_lltoa_e(long long n, int minus)
{
	int		size;
	char	*temp;

	size = get_llsize(n) + 1;
	if (minus == -1)
		size++;
	if ((temp = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		return (0);
	temp[size] = '\0';
	ft_lltoa_e2(n, minus, size, &temp);
	return (temp);
}

static int	get_index(long long n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (0);
	else
	{
		while (n != 0)
		{
			result++;
			n /= 10;
		}
	}
	return (result - 1);
}

char		*ft_dtoa_e(double n, int *e)
{
	long long	int_part;
	char		*result;

	int_part = n / 1;
	*e = get_index(int_part);
	while (int_part == 0)
	{
		n *= 10;
		(*e)--;
		int_part = n / 1;
	}
	if (n < 0)
		result = ft_lltoa_e(int_part, -1);
	else
		result = ft_lltoa_e(int_part, 1);
	if (result == 0)
		return (0);
	if (ft_dtoa2(n, int_part, &result) == 0)
	{
		free(result);
		return (0);
	}
	return (result);
}
