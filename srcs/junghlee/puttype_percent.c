/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:51:57 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 10:00:05 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

/*
** In-process
** - all specifiers except length
*/

static void	puttype_process(t_ptinfo *pt)
{
	if (pt->width > pt->print_size)
		pt->space += pt->width - pt->print_size;
	if (pt->props & (1 << PTF_FLAG_ZERO))
	{
		pt->zero = pt->space;
		pt->space = 0;
	}
	pt->print_size += pt->space + pt->zero;
}

static void	puttype_print(t_ptinfo *pt, char res)
{
	if (!(pt->props & (1 << PTF_FLAG_LEFT)))
		ptf_putcharn(' ', pt->space);
	ptf_putcharn('0', pt->zero);
	ptf_putcharn(res, 1);
	if (pt->props & (1 << PTF_FLAG_LEFT))
		ptf_putcharn(' ', pt->space);
}

int			ptf_puttype_percent(t_ptinfo *pt)
{
	char	res;

	res = '%';
	pt->print_size = 1;
	puttype_process(pt);
	puttype_print(pt, res);
	return (PTF_SUCCESS);
}
