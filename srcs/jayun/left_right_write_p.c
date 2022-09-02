/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_write_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:49:30 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 01:53:57 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_size_p(char *addr)
{
	int		result;

	result = ft_strlen(addr);
	if (g_pre == 1 && g_pre_num + 2 > result)
		result = g_pre_num + 2;
	if (g_width == 1 && g_width_num > result)
		result = g_width_num;
	return (result);
}

static void	pre_zero_p_r(char *addr, char **result, int i)
{
	int	len;

	if (g_pre == 1)
	{
		len = g_pre_num - (ft_strlen(addr) - 2);
		if (len > 0)
		{
			i += 2;
			while (len--)
				(*result)[i--] = '0';
			(*result)[i--] = 'x';
			(*result)[i--] = '0';
		}
	}
	else if (g_zero == 1)
	{
		i += 2;
		while (i >= 0)
			(*result)[i--] = '0';
		(*result)[1] = 'x';
	}
}

void		right_write_p(char *addr)
{
	char	*result;
	int		i;
	int		len;

	if ((result = malloc_size(get_size_p(addr))) == 0)
		return ;
	i = get_size_p(addr) - 1;
	len = ft_strlen(addr) - 1;
	while (len >= 0)
		result[i--] = addr[len--];
	pre_zero_p_r(addr, &result, i);
	add_result(result, get_size_p(addr));
	free(result);
}

void		left_write_p(char *addr)
{
	char	*result;
	int		i;
	int		len;
	int		j;

	if ((result = malloc_size(get_size_p(addr))) == 0)
		return ;
	i = 0;
	result[i++] = '0';
	result[i++] = 'x';
	if (g_pre == 1)
	{
		len = g_pre_num - (ft_strlen(addr) - 2);
		if (len > 0)
		{
			while (len--)
				result[i++] = '0';
		}
	}
	len = ft_strlen(addr);
	j = 2;
	while (j < len)
		result[i++] = addr[j++];
	add_result(result, get_size_p(addr));
	free(result);
}
