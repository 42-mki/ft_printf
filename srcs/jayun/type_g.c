/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:08:10 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 20:54:15 by jayun            ###   ########.fr       */
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
	{
		g_malloc_error = -1;
		return (0);
	}
	if (n != 0)
		rounding_check_gf(&temp);
	if (g_malloc_error == -1)
	{
		free(temp);
		return (0);
	}
	return (temp);
}

static char	*get_num_e(double n, int *e, char **num_f)
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
	{
		g_malloc_error = -1;
		free(*num_f);
		return (0);
	}
	if (n != 0)
		rounding_check_ge(&temp, e);
	if (g_malloc_error == -1)
	{
		free(temp);
		free(*num_f);
		return (0);
	}
	return (temp);
}

static void	type_g2(char *num_f, char *num_e, int e, int z)
{
	int	n;
	int	m;

	m = dot_place_check(num_f);
	n = number_place_check(num_f);
	if (((e < 6 && e > -5) || (n < m && g_pre_num + 1 >= m)) &&
			(e + 1 <= g_pre_num || e == 0 || g_pre == 0))
	{
		if (g_minus == 0)
			right_write_gf(num_f, z);
		else if (g_minus == 1)
			left_write_gf(num_f, z);
	}
	else
	{
		if (g_minus == 0)
			right_write_ge(num_e, e);
		else if (g_minus == 1)
			left_write_ge(num_e, e);
	}
}

int			type_g(const char *str, int left, int right)
{
	char	*num_f;
	char	*num_e;
	double	n;
	int		e;
	int		z;

	option_check(str, left, right);
	n = va_arg(g_ap, double);
	e = 0;
	z = 0;
	if ((num_f = get_num_f(n)) == 0)
		return (-1);
	if ((num_e = get_num_e(n, &e, &num_f)) == 0)
		return (-1);
	if (n == 0)
		z = 1;
	type_g2(num_f, num_e, e, z);
	free(num_f);
	free(num_e);
	return (g_malloc_error);
}
