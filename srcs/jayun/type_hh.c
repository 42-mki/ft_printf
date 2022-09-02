/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 22:44:59 by jayun             #+#    #+#             */
/*   Updated: 2020/10/27 00:47:28 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	type_hhdi(const char *str, int left, int right)
{
	char			*num;
	char			n;

	option_check(str, left, right);
	n = va_arg(g_ap, int);
	num = ft_itoa(n);
	if (num == 0)
		return (-1);
	if (g_minus == 0)
		right_write_dui(num, str[right]);
	else if (g_minus == 1)
		left_write_dui(num, str[right]);
	free(num);
	return (g_malloc_error);
}

static int	type_hhu(const char *str, int left, int right)
{
	char			*num;
	unsigned char	n;

	option_check(str, left, right);
	n = va_arg(g_ap, unsigned int);
	num = ft_itoa_u(n);
	if (num == 0)
		return (-1);
	if (g_minus == 0)
		right_write_dui(num, str[right]);
	else if (g_minus == 1)
		left_write_dui(num, str[right]);
	free(num);
	return (g_malloc_error);
}

static int	type_hhxo(const char *str, int left, int right)
{
	char			*base_num;
	unsigned char	num;

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

int			type_hh(const char *str, int left, int *right)
{
	int n;

	(*right)++;
	if (str[*right] == 'd' || str[*right] == 'i')
		n = type_hhdi(str, left, *right);
	else if (str[*right] == 'u')
		n = type_hhu(str, left, *right);
	else if (str[*right] == 'x' || str[*right] == 'X' || str[*right] == 'o')
		n = type_hhxo(str, left, *right);
	else
	{
		(*right)--;
		n = 1;
	}
	return (n);
}
