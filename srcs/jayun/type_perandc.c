/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_perandc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:36:42 by jayun             #+#    #+#             */
/*   Updated: 2020/10/27 17:42:42 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	type_perandc(const char *str, int left, int right)
{
	char	*c;

	option_check(str, left, right);
	if ((c = (char *)malloc(sizeof(char) * 2)) == 0)
		return (-1);
	c[0] = '%';
	c[1] = '\0';
	if (str[right] == 'c')
		c[0] = va_arg(g_ap, int);
	if (g_minus == 0)
		right_write_perandc(c);
	else if (g_minus == 1)
		left_write_perandc(c);
	free(c);
	return (g_malloc_error);
}
