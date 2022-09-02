/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:51:24 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 11:21:05 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

/*
** In-process
** - all specifiers except length
*/

static void	puttype_process(t_ptinfo *pt)
{
	if (pt->width > 1)
		pt->space += pt->width - 1;
	pt->print_size = 1 + pt->space;
}

static void	puttype_print(t_ptinfo *pt, char res)
{
	if (!(pt->props & (1 << PTF_FLAG_LEFT)))
		ptf_putcharn(' ', pt->space);
	ptf_putcharn(res, 1);
	if (pt->props & (1 << PTF_FLAG_LEFT))
		ptf_putcharn(' ', pt->space);
}

int			ptf_puttype_c(t_ptinfo *pt, va_list ap)
{
	char	res;

	res = (char)va_arg(ap, int);
	puttype_process(pt);
	puttype_print(pt, res);
	return (PTF_SUCCESS);
}
