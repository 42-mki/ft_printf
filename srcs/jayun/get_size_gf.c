/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_gf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:58:04 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 20:21:48 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_size_g1(char *num, int n)
{
	if (g_pre == 1)
		n += g_pre_num - 1;
	else
		n += 5;
	if (g_pre == 1 && g_pre_num == 0)
		n++;
	if (num[n] == '0' && num[n + 1] >= '5' && num[n + 1] <= '9')
		return (n - 1);
	while (num[n] == '0')
		n--;
	return (n);
}

static int	get_size_g2(char *num, int n, int i)
{
	if (g_pre == 1)
		n += g_pre_num;
	else
		n += 6;
	if (g_pre == 1 && g_pre_num == 1)
		n--;
	while (n >= (int)ft_strlen(num))
		n--;
	if (num[n] == '0' && num[n + 1] >= '5' && num[n + 1] <= '9')
		return (n);
	while (num[n] == '0' && n > i)
		n--;
	if (num[n] == '.')
		n--;
	return (n);
}

int			get_size_g(char *num)
{
	int	i;
	int	n;
	int	result;

	i = dot_place_check(num);
	n = number_place_check(num);
	if (num[n] == '\0' && num[0] == '-')
		return (2);
	else if (num[n] == '\0')
		return (1);
	if (n > i)
		result = get_size_g1(num, n);
	else
		result = get_size_g2(num, n, i);
	return (result + 1);
}

int			get_size_gf(char *num, int z)
{
	int	result;
	int	n;
	int	m;

	if (g_sharp == 1 && g_pre_num != 0)
		result = get_size_f(num) - 1;
	else
		result = get_size_g(num);
	n = dot_place_check(num);
	m = number_place_check(num);
	if (g_sharp == 1 && m > n && z == 0 && g_pre_num != 0)
		result++;
	if (g_sharp == 1 && m < n && g_pre_num == 0)
		result++;
	if (g_sharp == 1 && z == 1 && g_pre_num == 0)
		result++;
	if (num[0] != '-' && (g_plus == 1 || g_space == 1))
	{
		if ((g_sharp == 1 && g_pre_num == 0) || g_sharp != 1)
			result++;
	}
	if (g_width == 1 && result < g_width_num)
		result = g_width_num;
	return (result);
}
