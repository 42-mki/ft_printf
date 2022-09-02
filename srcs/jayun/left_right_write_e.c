/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_write_e.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:34:43 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 20:43:15 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	pre_e_r(char *num, char **result, int *i)
{
	int	len;
	int	j;

	len = ft_strlen(num) - 1;
	j = 0;
	while (num[j] != '.')
		j++;
	if (g_pre_num + j + 1 > len)
	{
		j = g_pre_num + j - len;
		while (j-- > 0)
			(*result)[(*i)--] = '0';
		while (len >= 0 && num[len] != '-')
			(*result)[(*i)--] = num[len--];
	}
	else if (g_pre_num + j + 1 <= len)
	{
		len = g_pre_num + j;
		if (g_pre_num == 0 && g_sharp != 1)
			len--;
		while (len >= 0 && num[len] != '-')
			(*result)[(*i)--] = num[len--];
	}
}

int			index_e_r(char **result, int e, int *i)
{
	char	*temp;
	int		j;

	temp = ft_itoa(e);
	if (temp == 0)
	{
		g_malloc_error = -1;
		free(*result);
		return (0);
	}
	j = ft_strlen(temp) - 1;
	(*result)[(*i)--] = temp[j--];
	if (e >= -9 && e <= 9)
		(*result)[(*i)--] = '0';
	else
		(*result)[(*i)--] = temp[j--];
	if (e < 0)
		(*result)[(*i)--] = '-';
	else
		(*result)[(*i)--] = '+';
	(*result)[(*i)--] = 'e';
	free(temp);
	return (1);
}

void		right_write_e(char *num, int e)
{
	char	*result;
	int		i;
	int		len;
	int		j;

	if ((result = malloc_size(get_size_e(num))) == 0)
		return ;
	i = get_size_e(num) - 1;
	len = ft_strlen(num) - 1;
	if (index_e_r(&result, e, &i) == 0)
		return ;
	j = dot_place_check(num);
	if (g_pre == 1)
		pre_e_r(num, &result, &i);
	else
	{
		len = 6 + j;
		while (len >= 0 && num[len] != '-')
			result[i--] = num[len--];
	}
	zero_sign_f_r(num, &result, &i);
	add_result(result, get_size_e(num));
	free(result);
}

int			index_e_l(char **result, int e, int i)
{
	char	*temp;
	int		j;

	(*result)[i++] = 'e';
	if (e < 0)
		(*result)[i++] = '-';
	else
		(*result)[i++] = '+';
	temp = ft_itoa(e);
	if (temp == 0)
	{
		g_malloc_error = -1;
		free(*result);
		return (0);
	}
	j = 0;
	if (e < 0)
		j = 1;
	if (e >= -9 && e <= 9)
		(*result)[i++] = '0';
	else
		(*result)[i++] = temp[j++];
	(*result)[i++] = temp[j++];
	free(temp);
	return (1);
}

void		left_write_e(char *num, int e)
{
	char	*result;
	int		i;
	int		len;
	int		j;
	int		k;

	if ((result = malloc_size(get_size_e(num))) == 0)
		return ;
	i = 0;
	len = ft_strlen(num) - 1;
	k = 0;
	sign_getdotj_f_l(num, &result, &i, &j);
	if (g_pre == 1)
		pre_f_l(num, &result, &i, j);
	else
	{
		len = 6 + j;
		while (len-- >= 0)
			result[i++] = num[k++];
	}
	if (index_e_l(&result, e, i) == 0)
		return ;
	add_result(result, get_size_e(num));
	free(result);
}
