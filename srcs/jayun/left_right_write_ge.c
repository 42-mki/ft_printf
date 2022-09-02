/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_write_ge.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:30:17 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 19:41:51 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_size_ge(char *num)
{
	int	result;

	result = get_size_g(num) + 4;
	if (g_width == 1 && result < g_width_num)
		result = g_width_num;
	return (result);
}

static void	pre_ge_r(char *num, char **result, int *i)
{
	int	len;
	int	j;

	len = ft_strlen(num) - 1;
	j = dot_place_check(num);
	if (g_pre_num == 1 || g_pre_num == 0)
		j--;
	if (g_pre_num + j + 1 > len)
	{
		len = get_size_g(num) - 1;
		while (len >= 0 && num[len] != '-')
			(*result)[(*i)--] = num[len--];
	}
	else if (g_pre_num + j + 1 <= len)
	{
		len = get_size_g(num) - 1;
		while (len >= 0 && num[len] != '-')
			(*result)[(*i)--] = num[len--];
	}
}

void		right_write_ge(char *num, int e)
{
	char	*result;
	int		i;
	int		len;
	int		j;

	if ((result = malloc_size(get_size_ge(num))) == 0)
		return ;
	i = get_size_ge(num) - 1;
	len = ft_strlen(num) - 1;
	if (index_e_r(&result, e, &i) == 0)
		return ;
	j = dot_place_check(num);
	if (g_pre == 1)
		pre_ge_r(num, &result, &i);
	else
	{
		len = get_size_g(num) - 1;
		while (len >= 0 && num[len] != '-')
			result[i--] = num[len--];
	}
	zero_sign_f_r(num, &result, &i);
	add_result(result, get_size_ge(num));
	free(result);
}

static void	pre_ge_l(char *num, char **result, int *i)
{
	int	len;
	int	k;

	k = 0;
	len = get_size_g(num) - 1;
	while (len-- >= 0)
		(*result)[(*i)++] = num[k++];
}

void		left_write_ge(char *num, int e)
{
	char	*result;
	int		i;
	int		len;
	int		j;
	int		k;

	if ((result = malloc_size(get_size_ge(num))) == 0)
		return ;
	i = 0;
	len = ft_strlen(num) - 1;
	k = 0;
	sign_getdotj_f_l(num, &result, &i, &j);
	if (g_pre == 1)
		pre_ge_l(num, &result, &i);
	else
	{
		len = get_size_g(num);
		while (len-- >= 0)
			result[i++] = num[k++];
	}
	if (index_e_l(&result, e, i) == 0)
		return ;
	add_result(result, get_size_ge(num));
	free(result);
}
