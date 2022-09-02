/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:13:47 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 01:14:52 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	add_result(char *str, int size)
{
	char	*temp;

	if (g_total_result == 0)
	{
		if ((g_total_result = ft_strdup_size(str, size)) == 0)
		{
			g_malloc_error = -1;
			return ;
		}
	}
	else
	{
		temp = ft_strjoin_size(g_total_result, str, g_total_len, size);
		free(g_total_result);
		if (temp == 0)
		{
			g_malloc_error = -1;
			return ;
		}
		g_total_result = temp;
	}
	g_total_len += size;
}

void	add_result2(char c)
{
	char	*temp;
	char	*str;

	if ((str = malloc_size(1)) == 0)
		return ;
	str[0] = c;
	if (g_total_result == 0)
	{
		if ((g_total_result = ft_strdup(str)) == 0)
			g_malloc_error = -1;
	}
	else
	{
		temp = ft_strjoin_size(g_total_result, str, g_total_len, 1);
		free(g_total_result);
		if (temp == 0)
			g_malloc_error = -1;
		else
			g_total_result = temp;
	}
	free(str);
	if (g_malloc_error != -1)
		g_total_len++;
}
