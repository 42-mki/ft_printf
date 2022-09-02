/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_write_gf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:52:37 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 19:55:29 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	pre_gf_r2(char *num, char **result, int *i, int z)
{
	int	j;
	int	n;
	int	len;

	j = dot_place_check(num);
	n = number_place_check(num);
	len = g_pre_num - 1 + j;
	if (g_pre_num == 0)
		len++;
	if (n > j && z == 0)
	{
		len++;
		j++;
	}
	while (len >= 0 && num[len] != '-')
		(*result)[(*i)--] = num[len--];
	if (g_pre_num == 0)
		j++;
}

static void	pre_gf_r1(char *num, char **result, int *i, int z)
{
	int	len;
	int	j;

	len = ft_strlen(num) - 1;
	j = dot_place_check(num);
	if (g_pre_num + j + 1 > len)
	{
		j = g_pre_num + j - len;
		while (j-- > 0)
			(*result)[(*i)--] = '0';
		len--;
		while (len >= 0 && num[len] != '-')
			(*result)[(*i)--] = num[len--];
	}
	else
		pre_gf_r2(num, &(*result), i, z);
}

static void	pre_gf_r(char *num, char **result, int *i, int z)
{
	int	len;
	int	n;
	int	j;

	j = dot_place_check(num);
	if (g_sharp == 1)
		pre_gf_r1(num, &(*result), i, z);
	else
	{
		len = get_size_g(num) - 1;
		n = len;
		while (len >= 0 && num[len] != '-')
			(*result)[(*i)--] = num[len--];
	}
}

static void	sharp_gf_r(char *num, char **result, int *i, int z)
{
	int	j;
	int	len;
	int	n;

	j = dot_place_check(num);
	len = 5 + j;
	n = number_place_check(num);
	if (n > j && z == 0)
		len++;
	while (len >= 0 && num[len] != '-')
		(*result)[(*i)--] = num[len--];
}

void		right_write_gf(char *num, int z)
{
	char	*result;
	int		i;
	int		len;
	int		j;

	if ((result = malloc_size(get_size_gf(num, z))) == 0)
		return ;
	i = get_size_gf(num, z) - 1;
	len = ft_strlen(num) - 1;
	j = dot_place_check(num);
	if (g_pre == 1)
		pre_gf_r(num, &result, &i, z);
	else if (g_sharp == 1)
		sharp_gf_r(num, &result, &i, z);
	else
	{
		len = get_size_g(num) - 1;
		while (len >= 0 && num[len] != '-')
			result[i--] = num[len--];
	}
	zero_sign_f_r(num, &result, &i);
	add_result(result, get_size_gf(num, z));
	free(result);
}
