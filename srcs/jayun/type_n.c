/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:19:56 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 21:20:25 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	type_n(const char *str, int left, int right)
{
	int	*result;

	option_check(str, left, right);
	result = va_arg(g_ap, int *);
	*result = g_total_len;
	return (g_malloc_error);
}
