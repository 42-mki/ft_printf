/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding_check_gf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:38:04 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 18:50:56 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	rounding_check_gf_get_i(char **num)
{
	int	i;
	int	n;

	i = dot_place_check(*num);
	n = number_place_check(*num);
	if (n > i)
	{
		i = n + 5;
		if (g_pre == 1 && g_pre_num != 0 && g_pre_num != 1)
			i = g_pre_num + n - 1;
		else if (g_pre == 1)
			i = n;
	}
	else
	{
		i = n + 6;
		if (g_pre == 1 && g_pre_num != 0 && g_pre_num != 1)
			i = g_pre_num;
		else if (g_pre == 1)
			i = n;
		if (g_pre == 1 && (*num)[0] == '-')
			i++;
	}
	return (i);
}

static void	rounding_check_gf2(char **num, char **result, int *i)
{
	if ((*num)[*i + 1] >= '5' && (*num)[*i + 1] <= '9')
	{
		if ((*num)[*i + 1] == '5')
			bankers_rounding(&(*num), &(*result), *i + 1);
		else
		{
			if ((*result)[*i] == '.')
				(*result)[*i - 1]++;
			else
				(*result)[*i]++;
		}
		(*result)[*i + 1] = '0';
	}
	else if ((*num)[*i + 1] == '.' &&
			(*num)[*i + 2] >= '5' && (*num)[*i + 2] <= '9')
	{
		if ((*num)[*i + 2] == '5')
			bankers_rounding(&(*num), &(*result), *i + 2);
		else
			(*result)[*i]++;
		(*result)[*i + 2] = '0';
	}
}

static void	rounding_check_gf1(char **num, char **result, int *i)
{
	rounding_check_gf2(&(*num), &(*result), i);
	while ((*i)-- && (*result)[*i] != '-')
	{
		if ((*result)[*i + 1] > '9' && (*result)[*i + 1] != '.')
		{
			(*result)[*i + 1] = '0';
			if ((*result)[*i] == '.')
				(*result)[*i - 1]++;
			else
				(*result)[*i]++;
		}
		else if ((*result)[*i + 1] <= '9' && (*result)[*i + 1] != '.')
			break ;
	}
}

static void	rounding_check_gf3(char **num, char **result)
{
	if ((*result)[1] > '9' && (*result)[0] == '-')
	{
		(*result)[1] = '0';
		(*result)[0] = '1';
		free(*num);
		*num = ft_strjoin("-", *result);
	}
	else if ((*result)[0] > '9' && (*result)[0] != '-')
	{
		(*result)[0] = '0';
		free(*num);
		*num = ft_strjoin("1", *result);
	}
	else
	{
		free(*num);
		*num = ft_strjoin(*result, "000000");
	}
	free(*result);
	if (*num == 0)
		g_malloc_error = -1;
}

void		rounding_check_gf(char **num)
{
	int		i;
	int		j;
	char	*result;

	i = rounding_check_gf_get_i(&(*num));
	j = i + 2;
	if ((g_pre_num == 0 || g_pre_num == 1) && g_pre == 1)
		j++;
	if ((result = malloc_size(j)) == 0)
		return ;
	while (--j >= 0)
		result[j] = (*num)[j];
	j = ft_strlen(*num);
	if (j > i + 1)
		rounding_check_gf1(&(*num), &result, &i);
	else
		result[i + 1] = '0';
	rounding_check_gf3(&(*num), &result);
}
