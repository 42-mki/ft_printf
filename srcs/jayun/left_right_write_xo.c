/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_write_xo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 02:01:44 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 02:04:36 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_size_xo(char *num, char type, unsigned int n)
{
	int	result;
	int	s;

	s = 2;
	if (type == 'o')
		s = 1;
	if (g_sharp == 0 || n == 0)
		s = 0;
	result = ft_strlen(num);
	if (n == 0 && g_pre_num == 0 && !(g_sharp == 1 && type == 'o'))
		result = 0;
	result += s;
	if (g_pre == 1 && type == 'o' && g_pre_num >= result)
		result = g_pre_num;
	else if (g_pre == 1 && (g_pre_num + s) > result)
		result = g_pre_num + s;
	if (g_width == 1 && g_width_num > result)
		result = g_width_num;
	return (result);
}

static void	pre_zero_xo_r(char *num, char **result, int *i)
{
	int	len;

	if (g_pre == 1)
	{
		len = g_pre_num - ft_strlen(num);
		if (len > 0)
			while (len--)
				(*result)[(*i)--] = '0';
	}
	else if (g_zero == 1)
		while (*i >= 0)
			(*result)[(*i)--] = '0';
}

void		right_write_xo(char *num, char type, unsigned int n)
{
	char	*result;
	int		i;
	int		len;

	if ((result = malloc_size(get_size_xo(num, type, n))) == 0)
		return ;
	i = get_size_xo(num, type, n) - 1;
	len = ft_strlen(num) - 1;
	while (len >= 0 && (n != 0 || g_pre_num != 0))
		result[i--] = num[len--];
	pre_zero_xo_r(num, &result, &i);
	if (g_sharp == 1 && n != 0 && !(g_zero == 1 && type == 'o'))
	{
		if (g_zero == 1)
			i += 2;
		if (type != 'o')
			result[i--] = type;
		if (!(type == 'o' && g_pre == 1 && g_pre_num > (int)ft_strlen(num)))
			result[i--] = '0';
	}
	if (g_sharp == 1 && type == 'o' && n == 0 && g_pre_num == 0)
		result[i--] = '0';
	add_result(result, get_size_xo(num, type, n));
	free(result);
}

static void	pre_zero_xo_l(char *num, char **result, int *i)
{
	int len;

	if (g_pre == 1)
	{
		len = g_pre_num - ft_strlen(num);
		if (len > 0)
			while (len--)
				(*result)[(*i)++] = '0';
	}
}

void		left_write_xo(char *num, char type, unsigned int n)
{
	char	*result;
	int		i;
	int		len;
	int		j;

	if ((result = malloc_size(get_size_xo(num, type, n))) == 0)
		return ;
	i = 0;
	if (g_sharp == 1 && n != 0)
	{
		if (!(type == 'o' && g_pre == 1 && g_pre_num > (int)ft_strlen(num)))
			result[i++] = '0';
		if (type != 'o')
			result[i++] = type;
	}
	if (g_sharp == 1 && type == 'o' && g_pre_num == 0 && n == 0)
		result[i++] = '0';
	pre_zero_xo_l(num, &result, &i);
	len = ft_strlen(num);
	j = -1;
	while (++j < len && (n != 0 || g_pre_num != 0))
		result[i++] = num[j];
	add_result(result, get_size_xo(num, type, n));
	free(result);
}
