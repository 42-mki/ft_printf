/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:00:07 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 02:45:40 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	option_init(void)
{
	g_minus = 0;
	g_zero = 0;
	g_width = 0;
	g_pre = 0;
	g_plus = 0;
	g_space = 0;
	g_sharp = 0;
	g_prime = 0;
}

static void	find_width(const char *str, int left, int right)
{
	int	i;

	i = left + 1;
	while (i < right && str[i] != '.')
	{
		if (str[i] == '*')
		{
			g_width = 1;
			g_width_num = va_arg(g_ap, int);
			break ;
		}
		else if (str[i] >= '1' && str[i] <= '9')
		{
			g_width = 1;
			g_width_num = ft_atoi((str + i));
			if (g_width_num < 0)
			{
				g_width_num *= -1;
				g_minus = 1;
			}
			break ;
		}
		i++;
	}
}

static void	find_flag(const char *str, int left, int right)
{
	int	i;

	i = left + 1;
	while (i < right)
	{
		if (str[i] == '0')
			g_zero = 1;
		else if (str[i] == '-')
			g_minus = 1;
		else if (str[i] == '+')
			g_plus = 1;
		else if (str[i] == 32)
			g_space = 1;
		else if (str[i] == '#')
			g_sharp = 1;
		else if (str[i] == '\'')
			g_prime = 1;
		else
			break ;
		i++;
	}
	if (g_minus == 1)
		g_zero = 0;
	if (g_plus == 1)
		g_space = 0;
}

static void	find_precision(const char *str, int left, int right)
{
	g_pre_num = -1;
	while (left < right && str[left] != '.')
		left++;
	if (str[left] == '.')
	{
		g_pre = 1;
		if (str[left + 1] == '*' || str[left + 1] == '-' ||
				(str[left + 1] >= '0' && str[left + 1] <= '9'))
		{
			if (str[left + 1] == '*')
			{
				g_pre_num = va_arg(g_ap, int);
				if (g_pre_num < 0)
					g_pre = 0;
			}
			else
				g_pre_num = ft_atoi((str + left + 1));
			if (g_pre_num == 0 && str[left + 1] == '-')
				g_minus = 1;
		}
		else
			g_pre_num = 0;
	}
}

void		option_check(const char *str, int left, int right)
{
	option_init();
	find_width(str, left, right);
	if (g_width_num < 0)
	{
		g_minus = 1;
		g_width_num *= -1;
	}
	find_flag(str, left, right);
	find_precision(str, left, right);
	if (g_pre == 1 && g_pre_num < 0)
	{
		g_pre = 0;
		g_width_num = g_pre_num * -1;
		g_width = 1;
		g_minus = 1;
		g_pre_num = 0;
		if (str[right] == 's' || str[right] == 'f' || str[right] == 'e')
			g_pre = 1;
	}
	if (g_pre == 1 && str[right] != 's' && str[right] != 'c' && str[right] !=
			'%' && str[right] != 'f' && str[right] != 'e' && str[right] != 'g')
		g_zero = 0;
}
