/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:41:53 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 01:48:52 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	type_s(const char *str, int left, int right)
{
	char	*c;

	option_check(str, left, right);
	c = va_arg(g_ap, char *);
	if (c == NULL)
		c = "(null)";
	if (g_minus == 0)
		right_write_s(c);
	else if (g_minus == 1)
		left_write_s(c);
	return (g_malloc_error);
}
