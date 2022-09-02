/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_l_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:41:53 by jayun             #+#    #+#             */
/*   Updated: 2020/10/27 00:58:09 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	type_lldi(const char *str, int left, int right)
{
	char		*num;
	long long	n;
	int			minus;

	option_check(str, left, right);
	n = va_arg(g_ap, long long);
	minus = 1;
	if (n < 0)
		minus = -1;
	num = ft_lltoa(n, minus);
	if (num == 0)
		return (-1);
	if (g_minus == 0)
		right_write_dui(num, str[right]);
	else if (g_minus == 1)
		left_write_dui(num, str[right]);
	free(num);
	return (g_malloc_error);
}

static int	type_llu(const char *str, int left, int right)
{
	char				*num;
	unsigned long long	n;

	option_check(str, left, right);
	n = va_arg(g_ap, unsigned long long);
	num = ft_lltoa_u(n, 1);
	if (num == 0)
		return (-1);
	if (g_minus == 0)
		right_write_dui(num, str[right]);
	else if (g_minus == 1)
		left_write_dui(num, str[right]);
	free(num);
	return (g_malloc_error);
}

static int	type_llxo(const char *str, int left, int right)
{
	char				*base_num;
	unsigned long long	num;

	option_check(str, left, right);
	num = va_arg(g_ap, unsigned long long);
	if ((base_num = get_basenum_ll(num, str[right])) == 0)
		return (-1);
	if (g_minus == 0)
		right_write_xo(base_num, str[right], num);
	else if (g_minus == 1)
		left_write_xo(base_num, str[right], num);
	free(base_num);
	return (g_malloc_error);
}

int			type_ll(const char *str, int left, int *right)
{
	int n;

	(*right)++;
	if (str[*right] == 'd' || str[*right] == 'i')
		n = type_lldi(str, left, *right);
	else if (str[*right] == 'u')
		n = type_llu(str, left, *right);
	else if (str[*right] == 'x' || str[*right] == 'X' || str[*right] == 'o')
		n = type_llxo(str, left, *right);
	else
	{
		(*right)--;
		n = 1;
	}
	return (n);
}

int			type_l(const char *str, int left, int *right)
{
	int n;

	(*right)++;
	if (str[*right] == 'l')
		n = type_ll(str, left, right);
	else if (str[*right] == 'd' || str[*right] == 'i')
		n = type_lldi(str, left, *right);
	else if (str[*right] == 'u')
		n = type_llu(str, left, *right);
	else if (str[*right] == 'x' || str[*right] == 'X' || str[*right] == 'o')
		n = type_llxo(str, left, *right);
	else
	{
		(*right)--;
		n = 1;
	}
	return (n);
}
