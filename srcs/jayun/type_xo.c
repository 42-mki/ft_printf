/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_xo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 02:05:13 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 20:13:38 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_basesize(unsigned int n, char type)
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

char		*get_basenum(unsigned int n, char type)
{
	char	*result;
	char	*base;
	int		i;
	int		j;

	if ((result = malloc_size(get_basesize(n, type))) == 0)
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
	i = get_basesize(n, type) - 1;
	while (i >= 0)
	{
		result[i] = base[n % j];
		n /= j;
		i--;
	}
	return (result);
}

int			type_xo(const char *str, int left, int right)
{
	char			*base_num;
	unsigned int	num;

	option_check(str, left, right);
	num = va_arg(g_ap, unsigned int);
	if ((base_num = get_basenum(num, str[right])) == 0)
		return (-1);
	if (g_minus == 0)
		right_write_xo(base_num, str[right], num);
	else if (g_minus == 1)
		left_write_xo(base_num, str[right], num);
	free(base_num);
	return (g_malloc_error);
}
