/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:52:37 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/17 21:57:50 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

/*
** In-process
** - all specifiers except length
*/

static void	puttype_process(t_ptinfo *pt, char *res)
{
	while (*(res + pt->print_size))
		pt->print_size++;
	if (pt->precision < 0)
		pt->precision = pt->print_size;
	else if (pt->precision > pt->print_size)
		pt->precision = pt->print_size;
	if (pt->width > pt->precision)
		pt->space = pt->width - pt->precision;
	pt->print_size = pt->precision + pt->space;
}

static void	puttype_print(t_ptinfo *pt, char *res)
{
	if (!(pt->props & (1 << PTF_FLAG_LEFT)))
		ptf_putcharn(' ', pt->space);
	ptf_putnstr(res, pt->precision);
	if (pt->props & (1 << PTF_FLAG_LEFT))
		ptf_putcharn(' ', pt->space);
}

int			ptf_puttype_s(t_ptinfo *pt, va_list ap)
{
	char	*res;

	res = va_arg(ap, char *);
	if (!res)
		res = "(null)";
	puttype_process(pt, res);
	puttype_print(pt, res);
	return (PTF_SUCCESS);
}
