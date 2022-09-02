/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding_check_ge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:22:47 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 18:23:57 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	rounding_check_ge2(char **num, int m)
{
	if ((*num)[2 + m] >= '5' && (*num)[2 + m] <= '9')
	{
		bankers_rounding(&(*num), &(*num), 2 + m);
		(*num)[2 + m] = '0';
	}
}

static int	rounding_check_ge1(char **num, int *e, int m)
{
	char	*temp;

	rounding_check_ge2(&(*num), m);
	if ((*num)[m] > '9')
	{
		if (m == 1)
			temp = ft_strjoin("-1.", "000000");
		else
			temp = ft_strjoin("1.", "000000");
		free(*num);
		if (temp == 0)
		{
			g_malloc_error = -1;
			return (0);
		}
		*num = temp;
		(*e)++;
	}
	return (1);
}

static void	rounding_check_ge3(char **num, int *i, int m)
{
	if ((*num)[*i + 1 + m] >= '5' && (*num)[*i + 1 + m] <= '9')
	{
		bankers_rounding(&(*num), &(*num), *i + 1 + m);
		(*num)[*i + 1 + m] = '0';
	}
	while (*i)
	{
		if ((*num)[*i + m] == '.')
			break ;
		if ((*num)[*i + 1 + m] > '9')
		{
			(*num)[*i + 1 + m] = '0';
			(*num)[*i + m]++;
		}
		(*i)--;
	}
}

static int	rounding_check_ge4(char **num, int *e, int m)
{
	char	*temp;

	if ((*num)[m + 2] > '9')
	{
		(*num)[m + 2] = '0';
		(*num)[m]++;
	}
	if ((*num)[m] > '9')
	{
		(*num)[m + 1] = '0';
		(*num)[m] = '.';
		if (m == 1)
			(*num)[0] = '1';
		if (m == 1)
			temp = ft_strjoin("-", *num);
		else
			temp = ft_strjoin("1", *num);
		free(*num);
		if (temp == 0)
			return (0);
		*num = temp;
		(*e)++;
	}
	return (1);
}

void		rounding_check_ge(char **num, int *e)
{
	int	i;
	int	m;

	m = 0;
	if ((*num)[0] == '-')
		m = 1;
	if (g_pre == 1 && (g_pre_num == 0 || g_pre_num == 1))
	{
		if (rounding_check_ge1(&(*num), e, m) == 0)
			return ;
	}
	else
	{
		if (g_pre == 1 && g_pre_num > 1)
			i = g_pre_num;
		else
			i = 6;
		rounding_check_ge3(&(*num), &i, m);
		if (rounding_check_ge4(&(*num), e, m) == 0)
			g_malloc_error = -1;
	}
}
