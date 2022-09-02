/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_write_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:39:40 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 01:49:02 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_size_s(char *str)
{
	int	result;

	result = ft_strlen(str);
	if (g_pre == 1 && result > g_pre_num)
		result = g_pre_num;
	if (g_width == 1 && result < g_width_num)
		result = g_width_num;
	return (result);
}

void		right_write_s(char *str)
{
	char	*result;
	int		i;
	int		len;

	if ((result = malloc_size(get_size_s(str))) == 0)
		return ;
	i = get_size_s(str) - 1;
	len = ft_strlen(str);
	if (g_pre == 1 && g_pre_num < len)
		len = g_pre_num;
	while (len--)
		result[i--] = str[len];
	if (g_zero == 1)
		while (i >= 0)
			result[i--] = '0';
	add_result(result, get_size_s(str));
	free(result);
}

void		left_write_s(char *str)
{
	char	*result;
	int		i;
	int		len;

	if ((result = malloc_size(get_size_s(str))) == 0)
		return ;
	i = -1;
	len = ft_strlen(str);
	if (g_pre == 1 && g_pre_num < len)
		len = g_pre_num;
	while (++i < len)
		result[i] = str[i];
	add_result(result, get_size_s(str));
	free(result);
}
