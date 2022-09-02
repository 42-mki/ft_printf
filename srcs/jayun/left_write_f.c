/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_write_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:05:43 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 21:07:25 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	pre_f_l(char *num, char **result, int *i, int j)
{
	int	len;
	int	k;

	len = ft_strlen(num) - 1;
	k = 0;
	if (g_pre_num + j + 1 > len)
	{
		while (k <= len)
			(*result)[(*i)++] = num[k++];
		j = g_pre_num + j - len;
		while (j-- > 0)
			(*result)[(*i)++] = '0';
	}
	else if (g_pre_num + j + 1 <= len)
	{
		len = g_pre_num + j;
		if (g_pre_num == 0 && g_sharp != 1)
			len--;
		while (len-- >= 0)
			(*result)[(*i)++] = num[k++];
	}
}

void	sign_getdotj_f_l(char *num, char **result, int *i, int *j)
{
	*j = 0;
	while (num[*j] != '.')
		(*j)++;
	if (g_plus == 1 && num[0] != '-')
		(*result)[(*i)++] = '+';
	else if (g_space == 1 && num[0] != '-')
		(*result)[(*i)++] = 32;
}

void	left_write_f(char *num)
{
	char	*result;
	int		i;
	int		len;
	int		j;
	int		k;

	if ((result = malloc_size(get_size_f(num))) == 0)
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
	add_result(result, get_size_f(num));
	free(result);
}
