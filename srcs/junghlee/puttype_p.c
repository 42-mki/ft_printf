/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:57:15 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 10:30:21 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

/*
** Pre-process
** - length
** - sign
*/

static void	puttype_preprocess(va_list ap, t_ull *num)
{
	*num = (unsigned long long)va_arg(ap, unsigned long long);
}

/*
** In-process
** - all specifiers except length
*/

static void	puttype_process(t_ptinfo *pt, t_ull num)
{
	pt->print_size += 2;
	if (!num && pt->precision)
		pt->zero++;
	if (pt->width > pt->print_size + pt->zero)
		pt->space += pt->width - pt->print_size - pt->zero;
	pt->print_size += pt->space + pt->zero;
}

static void	puttype_print(t_ptinfo *pt, char *res)
{
	if (!(pt->props & (1 << PTF_FLAG_LEFT)))
		ptf_putcharn(' ', pt->space);
	if (pt->props & (1 << PTF_NEGATIVE))
		ptf_putcharn('-', 1);
	else if (pt->props & (1 << PTF_FLAG_PLUS))
		ptf_putcharn('+', 1);
	if (pt->type == 'p')
		ptf_putstr("0x");
	ptf_putcharn('0', pt->zero);
	ptf_putstr(res);
	if (pt->props & (1 << PTF_FLAG_LEFT))
		ptf_putcharn(' ', pt->space);
}

int			ptf_puttype_p(t_ptinfo *pt, va_list ap)
{
	t_ull	num;
	char	*res;

	puttype_preprocess(ap, &num);
	if (!(res = ptf_ulltoa(pt, num, 16ULL, "0123456789abcdef")))
		return (PTF_ERROR);
	puttype_process(pt, num);
	puttype_print(pt, res);
	free(res);
	return (PTF_SUCCESS);
}
