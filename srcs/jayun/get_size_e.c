/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:47:04 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 20:47:53 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	get_size_e(char *num)
{
	int	result;
	int	len;

	len = 0;
	while (num[len] != '.')
		len++;
	if (g_pre == 1 && g_pre_num == 0 && g_sharp != 1)
		len--;
	result = len + 1 + 6 + 4;
	if (num[0] != '-' && (g_space == 1 || g_plus == 1))
	{
		result++;
		if (g_pre == 1)
			result = len + 1 + g_pre_num + 4 + 1;
	}
	else if (g_pre == 1)
		result = len + 1 + g_pre_num + 4;
	if (g_width == 1 && result < g_width_num)
		result = g_width_num;
	return (result);
}
