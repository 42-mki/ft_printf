/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_write_perandc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:32:45 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 01:47:08 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_size_perandc(char *c)
{
	int	result;

	result = ft_strlen(c);
	if (c[0] == '\0')
		result = 1;
	if (g_width == 1 && g_width_num > result)
		result = g_width_num;
	return (result);
}

void		right_write_perandc(char *c)
{
	char	*result;
	int		i;
	int		len;

	if ((result = malloc_size(get_size_perandc(c))) == 0)
		return ;
	i = get_size_perandc(c) - 1;
	len = ft_strlen(c) - 1;
	while (len >= 0)
		result[i--] = c[len--];
	if (c[0] == '\0')
		result[i--] = '\0';
	if (g_zero == 1)
	{
		while (i >= 0)
			result[i--] = '0';
	}
	add_result(result, get_size_perandc(c));
	free(result);
}

void		left_write_perandc(char *c)
{
	char	*result;
	int		i;
	int		len;
	int		j;

	if ((result = malloc_size(get_size_perandc(c))) == 0)
		return ;
	i = 0;
	len = ft_strlen(c);
	j = -1;
	while (++j < len)
		result[i++] = c[j];
	if (c[0] == '\0')
		result[i++] = '\0';
	add_result(result, get_size_perandc(c));
	free(result);
}
