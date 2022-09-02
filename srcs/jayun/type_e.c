/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:23:03 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 20:34:09 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*get_num_e(double n, int *e)
{
	char		*temp;
	t_double	a;

	a.double_value = n;
	if (n != 0)
		temp = ft_dtoa_e(n, e);
	else if (a.s_int.sign == 0)
		temp = ft_strdup("0.000000");
	else
		temp = ft_strdup("-0.000000");
	if (temp == 0)
		return (0);
	return (temp);
}

int			type_e(const char *str, int left, int right)
{
	char		*num;
	double		n;
	int			e;

	option_check(str, left, right);
	n = va_arg(g_ap, double);
	e = 0;
	num = get_num_e(n, &e);
	if (num == 0)
		return (-1);
	if (n != 0)
		rounding_check_e(&num, &e);
	if (g_malloc_error == -1)
		return (-1);
	if (g_minus == 0)
		right_write_e(num, e);
	else if (g_minus == 1)
		left_write_e(num, e);
	free(num);
	return (g_malloc_error);
}
