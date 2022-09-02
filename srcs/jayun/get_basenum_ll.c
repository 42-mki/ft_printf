/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_basenum_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:39:38 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 23:44:40 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_basesize_ll(unsigned long long n, char type)
{
	int	count;
	int	i;

	i = 16;
	if (type == 'o')
		i = 8;
	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= i;
	}
	return (count);
}

char		*get_basenum_ll(unsigned long long n, char type)
{
	char	*result;
	char	*base;
	int		i;
	int		j;

	if ((result = malloc_size(get_basesize_ll(n, type))) == 0)
		return (0);
	if (type == 'x')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	else if (type == 'o')
		base = "01234567";
	j = 16;
	if (type == 'o')
		j = 8;
	i = get_basesize_ll(n, type) - 1;
	while (i >= 0)
	{
		result[i] = base[n % j];
		n /= j;
		i--;
	}
	return (result);
}
