/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype_uox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:57:15 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 23:45:26 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

/*
** Pre-process
** - length
** - sign
*/

static void	puttype_preprocess(t_ptinfo *pt, va_list ap, t_ull *num)
{
	if (pt->props & (1 << PTF_LENGTH_HH))
		*num = (unsigned char)va_arg(ap, unsigned int);
	else if (pt->props & (1 << PTF_LENGTH_H))
		*num = (unsigned short)va_arg(ap, unsigned int);
	else if (pt->props & (1 << PTF_LENGTH_LL))
		*num = (unsigned long long)va_arg(ap, unsigned long long);
	else if (pt->props & (1 << PTF_LENGTH_L))
		*num = (unsigned long)va_arg(ap, unsigned long);
	else
		*num = (unsigned int)va_arg(ap, unsigned int);
	if (!(*num))
		pt->props &= ~(1 << PTF_FLAG_SHARP);
}

/*
** In-process
** - all specifiers except length
*/

static void	puttype_process(t_ptinfo *pt, t_ull num)
{
	if (pt->precision > pt->print_size)
		pt->zero += pt->precision - pt->print_size;
	else if (pt->precision < 0 && !num)
		pt->zero++;
	if (pt->props & (1 << PTF_FLAG_SHARP))
	{
		if (pt->type == 'o')
			pt->print_size += 1;
		else if (pt->type == 'x' || pt->type == 'X')
			pt->print_size += 2;
	}
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

static void	puttype_addprefix(t_ptinfo *pt)
{
	if (!pt->print_size && !pt->precision)
		return ;
	if (pt->type == 'o')
		ptf_putstr("0");
	else if (pt->type == 'x' || pt->type == 'X')
	{
		ptf_putcharn('0', 1);
		ptf_putcharn(pt->type, 1);
	}
}

static void	puttype_print(t_ptinfo *pt, char *res)
{
	if (!(pt->props & (1 << PTF_FLAG_LEFT)))
		ptf_putcharn(' ', pt->space);
	if (pt->props & (1 << PTF_FLAG_SHARP))
		puttype_addprefix(pt);
	ptf_putcharn('0', pt->zero);
	ptf_putstr(res);
	if (pt->props & (1 << PTF_FLAG_LEFT))
		ptf_putcharn(' ', pt->space);
}

int			ptf_puttype_uox(t_ptinfo *pt, va_list ap)
{
	t_ull	num;
	char	*res;

	puttype_preprocess(pt, ap, &num);
	res = 0;
	if (pt->type == 'u')
		res = ptf_ulltoa(pt, num, 10ULL, "0123456789");
	else if (pt->type == 'o')
		res = ptf_ulltoa(pt, num, 8ULL, "01234567");
	else if (pt->type == 'x')
		res = ptf_ulltoa(pt, num, 16ULL, "0123456789abcdef");
	else if (pt->type == 'X')
		res = ptf_ulltoa(pt, num, 16ULL, "0123456789ABCDEF");
	if (!res)
		return (PTF_ERROR);
	puttype_process(pt, num);
	puttype_print(pt, res);
	free(res);
	return (PTF_SUCCESS);
}
