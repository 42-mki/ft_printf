/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:23:31 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 14:15:05 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

/*
** Pre-process
** - length
** - sign
*/

static void	puttype_preprocess(t_ptinfo *pt, va_list ap, t_ll *num)
{
	if (pt->props & (1 << PTF_LENGTH_HH))
		*num = (char)va_arg(ap, int);
	else if (pt->props & (1 << PTF_LENGTH_H))
		*num = (short)va_arg(ap, int);
	else if (pt->props & (1 << PTF_LENGTH_LL))
		*num = (long long)va_arg(ap, long long);
	else if (pt->props & (1 << PTF_LENGTH_L))
		*num = (long)va_arg(ap, long);
	else
		*num = (int)va_arg(ap, int);
	if (*num < 0)
	{
		pt->props |= ((1 << PTF_FLAG_PLUS) | (1 << PTF_NEGATIVE));
		(*num) *= -1LL;
	}
}

/*
** In-process
** - all specifiers except length
*/

static void	puttype_process(t_ptinfo *pt, t_ll num)
{
	if (pt->precision > pt->print_size)
		pt->zero += pt->precision - pt->print_size;
	else if (pt->precision < 0 && !num)
		pt->zero++;
	if ((pt->props & (1 << PTF_FLAG_PLUS)) ||
		(pt->props & (1 << PTF_FLAG_EMPTY)))
		pt->print_size++;
	if (pt->width > pt->print_size + pt->zero)
	{
		if (pt->props & (1 << PTF_FLAG_ZERO))
		{
			if (pt->precision < 0)
				pt->zero += pt->width - pt->print_size - pt->zero;
			else if (pt->precision > pt->print_size + pt->zero && num)
				pt->zero += pt->width - pt->print_size - pt->zero;
		}
		if (pt->width > pt->space + pt->zero + pt->print_size)
			pt->space += pt->width - pt->print_size - pt->space - pt->zero;
	}
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
	else if (pt->props & (1 << PTF_FLAG_EMPTY))
		ptf_putcharn(' ', 1);
	ptf_putcharn('0', pt->zero);
	ptf_putstr(res);
	if (pt->props & (1 << PTF_FLAG_LEFT))
		ptf_putcharn(' ', pt->space);
}

int			ptf_puttype_di(t_ptinfo *pt, va_list ap)
{
	t_ll	num;
	char	*res;

	puttype_preprocess(pt, ap, &num);
	if (!(res = ptf_ulltoa(pt, (t_ull)num, 10ULL, "0123456789")))
		return (PTF_ERROR);
	puttype_process(pt, num);
	puttype_print(pt, res);
	free(res);
	return (PTF_SUCCESS);
}
