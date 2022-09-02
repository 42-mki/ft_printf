/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:54:34 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 01:57:24 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int				get_addrsize(void *str)
{
	unsigned long	n;
	int				result;

	result = 0;
	n = (unsigned long)str;
	while (n != 0)
	{
		result++;
		n /= 16;
	}
	return (result + 2);
}

static unsigned char	*get_address(void *str)
{
	unsigned long	n;
	unsigned char	*result;
	char			*hex;
	int				size;

	if (str == NULL && g_pre_num == 0)
		return ((unsigned char *)ft_strdup("0x"));
	else if (str == NULL && g_pre_num != 0)
		return ((unsigned char *)ft_strdup("0x0"));
	size = get_addrsize(str);
	if ((result = (unsigned char *)malloc(sizeof(unsigned char) *
					(size + 1))) == 0)
		return (0);
	result[size] = '\0';
	hex = "0123456789abcdef";
	n = (unsigned long)str;
	while (--size >= 2)
	{
		result[size] = hex[n % 16];
		n /= 16;
	}
	result[0] = '0';
	result[1] = 'x';
	return (result);
}

int						type_p(const char *str, int left, int right)
{
	unsigned char	*addr;

	option_check(str, left, right);
	if ((addr = get_address(va_arg(g_ap, void *))) == 0)
		return (-1);
	if (g_minus == 0)
		right_write_p((char *)addr);
	else if (g_minus == 1)
		left_write_p((char *)addr);
	free(addr);
	return (g_malloc_error);
}
