/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_write_gf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:42:13 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 19:48:54 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	pre_gf_l2(char *num, char **result, int *i, int z)
{
	int	len;
	int	j;
	int	n;
	int	k;

	j = dot_place_check(num);
	len = g_pre_num - 1 + j;
	if (g_pre_num == 0)
		len++;
	n = number_place_check(num);
	if (z == 0 && n > j)
		len++;
	k = 0;
	while (len-- >= 0)
		(*result)[(*i)++] = num[k++];
}

static void	pre_gf_l1(char *num, char **result, int *i, int z)
{
	int	len;
	int	j;
	int	k;

	len = ft_strlen(num) - 1;
	j = dot_place_check(num);
	k = 0;
	if (g_pre_num + j + 1 > len)
	{
		while (k <= len - 1)
			(*result)[(*i)++] = num[k++];
		j = g_pre_num + j - len;
		while (j-- > 0)
			(*result)[(*i)++] = '0';
	}
	else if (g_pre_num + j + 1 <= len)
		pre_gf_l2(num, &(*result), i, z);
}

static void	pre_gf_l(char *num, char **result, int *i, int z)
{
	int	len;
	int	k;
	int	j;

	k = 0;
	j = dot_place_check(num);
	if (g_sharp == 1)
		pre_gf_l1(num, &(*result), i, z);
	else
	{
		len = get_size_g(num) - 1;
		while (len-- >= 0)
			(*result)[(*i)++] = num[k++];
	}
}

static void	sharp_gf_l(char *num, char **result, int *i, int z)
{
	int	len;
	int	j;
	int	n;
	int	k;

	j = dot_place_check(num);
	len = 5 + j;
	n = number_place_check(num);
	k = 0;
	if (n > j && z == 0)
		len++;
	while (len-- >= 0)
		(*result)[(*i)++] = num[k++];
}

void		left_write_gf(char *num, int z)
{
	char	*result;
	int		i;
	int		len;
	int		k;

	if ((result = malloc_size(get_size_gf(num, z))) == 0)
		return ;
	i = 0;
	k = 0;
	if (g_plus == 1 && num[0] != '-')
		result[i++] = '+';
	else if (g_space == 1 && num[0] != '-')
		result[i++] = 32;
	if (g_pre == 1)
		pre_gf_l(num, &result, &i, z);
	else if (g_sharp == 1)
		sharp_gf_l(num, &result, &i, z);
	else
	{
		len = get_size_g(num) - 1;
		while (len-- >= 0)
			result[i++] = num[k++];
	}
	add_result(result, get_size_gf(num, z));
	free(result);
}
