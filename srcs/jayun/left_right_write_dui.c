/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_write_dui.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:19:31 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 01:25:48 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_size_dui(char *num, char type)
{
	int result;

	result = ft_strlen(num);
	if (num[0] == '0' && num[1] == '\0' && g_pre_num == 0)
		result = 0;
	if (type != 'u' && num[0] != '-' && (g_space == 1 || g_plus == 1))
		result++;
	if (g_pre == 1)
	{
		if (type != 'u' && (num[0] == '-' || g_space == 1 || g_plus == 1))
		{
			if (g_pre_num + 1 > result)
				result = g_pre_num + 1;
		}
		else
		{
			if (g_pre_num > result)
				result = g_pre_num;
		}
	}
	if (g_width == 1 && g_width_num > result)
		result = g_width_num;
	return (result);
}

static void	sign_dui(char sign, char **result, int *i)
{
	if (*i >= 0)
	{
		if (sign == '-')
			(*result)[(*i)++] = '-';
		else if (g_plus == 1)
			(*result)[(*i)++] = '+';
		else if (g_space == 1)
			(*result)[(*i)++] = 32;
	}
	else
	{
		if (sign == '-')
			(*result)[0] = '-';
		else if (g_plus == 1)
			(*result)[0] = '+';
		else if (g_space == 1)
			(*result)[0] = 32;
	}
}

static void	pre_zero_dui(char *num, char **result, int *i, int type)
{
	int	len;

	if (g_pre == 1 && type == 1)
	{
		len = g_pre_num - ft_strlen(num);
		if (num[0] == '-')
			len++;
		if (len > 0)
			while (len--)
				(*result)[(*i)--] = '0';
	}
	else if (g_zero == 1 && type == 1)
	{
		while (*i >= 0)
			(*result)[(*i)--] = '0';
	}
	else if (g_pre == 1 && type == 2)
	{
		len = g_pre_num - ft_strlen(num);
		if (num[0] == '-')
			len++;
		if (len > 0)
			while (len--)
				(*result)[(*i)++] = '0';
	}
}

void		right_write_dui(char *num, char type)
{
	char	*result;
	int		i;
	int		len;

	if ((result = malloc_size(get_size_dui(num, type))) == 0)
		return ;
	i = get_size_dui(num, type) - 1;
	len = ft_strlen(num) - 1;
	while (len >= 0 && num[len] != '-' && (num[0] != '0' || g_pre_num != 0))
		result[i--] = num[len--];
	pre_zero_dui(num, &result, &i, 1);
	if (type != 'u')
		sign_dui(num[0], &result, &i);
	add_result(result, get_size_dui(num, type));
	free(result);
}

void		left_write_dui(char *num, char type)
{
	char	*result;
	int		i;
	int		len;
	int		j;

	if ((result = malloc_size(get_size_dui(num, type))) == 0)
		return ;
	i = 0;
	if (type != 'u')
		sign_dui(num[0], &result, &i);
	pre_zero_dui(num, &result, &i, 2);
	len = ft_strlen(num);
	j = -1;
	if (num[0] == '-' && num[1] >= '0')
		j = 0;
	while (++j < len && (num[0] != '0' || g_pre_num != 0))
		result[i++] = num[j];
	add_result(result, get_size_dui(num, type));
	free(result);
}
