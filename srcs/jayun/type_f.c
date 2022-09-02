/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:56:54 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 21:05:22 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*get_num_f(double n)
{
	char		*temp;
	t_double	a;

	a.double_value = n;
	if (n != 0)
		temp = ft_dtoa(n);
	else if (a.s_int.sign == 0)
		temp = ft_strdup("0.000000");
	else
		temp = ft_strdup("-0.000000");
	if (temp == 0)
		return (0);
	return (temp);
}

int			type_f(const char *str, int left, int right)
{
	char		*num;
	double		n;

	option_check(str, left, right);
	n = va_arg(g_ap, double);
	num = get_num_f(n);
	if (num == 0)
		return (-1);
	if (n != 0)
		rounding_check_f(&num);
	if (g_malloc_error == -1)
		return (-1);
	if (g_minus == 0)
		right_write_f(num);
	else if (g_minus == 1)
		left_write_f(num);
	free(num);
	return (g_malloc_error);
}
