/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_write_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:08:36 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 21:11:00 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	pre_f_r(char *num, char **result, int *i)
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

void		zero_sign_f_r(char *num, char **result, int *i)
{
	if (g_zero == 1)
	{
		while (*i >= 0)
			(*result)[(*i)--] = '0';
		if (num[0] == '-')
			(*result)[0] = '-';
		else if (g_plus == 1)
			(*result)[0] = '+';
		else if (g_space == 1)
			(*result)[0] = 32;
	}
	else
	{
		if (num[0] == '-')
			(*result)[(*i)--] = '-';
		else if (g_plus == 1)
			(*result)[(*i)--] = '+';
		else if (g_space == 1)
			(*result)[(*i)--] = 32;
	}
}

void		right_write_f(char *num)
{
	char	*result;
	int		i;
	int		len;
	int		j;

	if ((result = malloc_size(get_size_f(num))) == 0)
		return ;
	i = get_size_f(num) - 1;
	len = ft_strlen(num) - 1;
	j = 0;
	while (num[j] != '.')
		j++;
	if (g_pre == 1)
		pre_f_r(num, &result, &i);
	else
	{
		len = 6 + j;
		while (len >= 0 && num[len] != '-')
			result[i--] = num[len--];
	}
	zero_sign_f_r(num, &result, &i);
	add_result(result, get_size_f(num));
	free(result);
}
