/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:34:05 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 22:02:37 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

int	ptf_puttype_n(int total_print_len, va_list ap)
{
	int *res_len;

	res_len = (int *)va_arg(ap, int *);
	if (!res_len)
		return (PTF_ERROR);
	*res_len = total_print_len;
	return (PTF_SUCCESS);
}
