/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:23:51 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 19:57:20 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_LEN 19

static int	ft_isspace(const char c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int			ft_atoi(const char *str)
{
	char	arr[MAX_LEN + 1];
	char	*p_arr;
	int		sign;
	int		result;

	while (ft_isspace(*str))
		++str;
	sign = (*str == '-' ? -1 : 1);
	if (sign == -1 || *str == '+')
		++str;
	while (*str == '0')
		++str;
	p_arr = arr;
	while (ft_isdigit(*str) && p_arr - arr < MAX_LEN)
		*p_arr++ = *str++;
	if (p_arr - arr == MAX_LEN)
		return ((-sign - 1) / 2);
	*(p_arr) = '\0';
	p_arr = arr;
	result = 0;
	while (*p_arr)
		result = result * 10 + (*p_arr++ - '0');
	return (sign * result);
}
