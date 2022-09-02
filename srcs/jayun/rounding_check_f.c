/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding_check_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:37:58 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 21:38:56 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	rounding_check_f_get_i(char **num)
{
	int	i;
	int	n;

	n = dot_place_check(*num);
	i = n + 6;
	if (g_pre == 1)
		i = g_pre_num + n;
	if (g_pre == 1 && g_pre_num == 0)
		i--;
	return (i);
}

static void	rounding_check_f2(char **num, char **result, int *i)
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

static void	rounding_check_f1(char **num, char **result, int *i)
{
	rounding_check_f2(&(*num), &(*result), i);
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

static void	rounding_check_f3(char **num, char **result)
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

void		rounding_check_f(char **num)
{
	int		i;
	int		j;
	char	*result;

	i = rounding_check_f_get_i(&(*num));
	j = i + 2;
	if ((result = malloc_size(j)) == 0)
		return ;
	while (--j >= 0)
		result[j] = (*num)[j];
	j = ft_strlen(*num);
	if (j > i + 1)
		rounding_check_f1(&(*num), &result, &i);
	else
		result[i + 1] = '0';
	rounding_check_f3(&(*num), &result);
}
