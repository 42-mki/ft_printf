/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:15:31 by jayun             #+#    #+#             */
/*   Updated: 2020/10/27 00:11:43 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		get_llsize(long long n)
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

char	*ft_lltoa(long long n, int minus)
{
	char	*temp;
	int		size;

	size = get_llsize(n);
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

int		ft_dtoa2(double n, long long int_part, char **result)
{
	char	*temp1;
	char	*temp2;
	int		size;

	size = 7;
	while (n != 0 || size-- > 0)
	{
		n -= int_part;
		if (n < 0)
			n *= -1;
		n *= 10;
		int_part = n / 1;
		if ((temp1 = ft_lltoa(int_part, 1)) == 0)
			return (0);
		if ((temp2 = ft_strjoin(*result, temp1)) == 0)
		{
			free(temp1);
			return (0);
		}
		free(*result);
		free(temp1);
		*result = temp2;
	}
	return (1);
}

char	*ft_dtoa(double n)
{
	long long	int_part;
	char		*result;
	char		*temp1;

	int_part = n / 1;
	if (n < 0)
		result = ft_lltoa(int_part, -1);
	else
		result = ft_lltoa(int_part, 1);
	if (result == 0)
		return (0);
	temp1 = ft_strjoin(result, ".");
	free(result);
	if (temp1 == 0)
		return (0);
	result = temp1;
	if (ft_dtoa2(n, int_part, &result) == 0)
	{
		free(result);
		return (0);
	}
	return (result);
}
