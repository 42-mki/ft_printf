/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_dui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:28:41 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 19:50:15 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	type_dui(const char *str, int left, int right)
{
	char	*num;

	option_check(str, left, right);
	if (str[right] == 'u')
		num = ft_itoa_u(va_arg(g_ap, unsigned int));
	else
		num = ft_itoa(va_arg(g_ap, int));
	if (num == 0)
		return (-1);
	if (g_minus == 0)
		right_write_dui(num, str[right]);
	else if (g_minus == 1)
		left_write_dui(num, str[right]);
	free(num);
	return (g_malloc_error);
}
