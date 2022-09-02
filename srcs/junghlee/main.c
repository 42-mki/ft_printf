/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:02:26 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 22:01:39 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

static void		ptf_init_info(t_ptinfo *pt)
{
	pt->props = 0;
	pt->type = '\0';
	pt->width = 0;
	pt->precision = -1;
	pt->zero = 0;
	pt->space = 0;
	pt->print_size = 0;
}

static size_t	ptf_parse(const char *format, t_ptinfo *pt, va_list ap)
{
	size_t	len;

	len = 1;
	len += ptf_parse_flag(format + len, pt);
	len += ptf_parse_width(format + len, pt, ap);
	len += ptf_parse_precision(format + len, pt, ap);
	len += ptf_parse_length(format + len, pt);
	len += ptf_parse_type(format + len, pt);
	return (len);
}

static int		ptf_puttype(t_ptinfo *pt, va_list ap, int *print_len)
{
	if (pt->type == 'c')
		return (ptf_puttype_c(pt, ap));
	else if (pt->type == '%')
		return (ptf_puttype_percent(pt));
	else if (pt->type == 's')
		return (ptf_puttype_s(pt, ap));
	else if (pt->type == 'd' || pt->type == 'i')
		return (ptf_puttype_di(pt, ap));
	else if (pt->type == 'u' || pt->type == 'o'
			|| pt->type == 'x' || pt->type == 'X')
		return (ptf_puttype_uox(pt, ap));
	else if (pt->type == 'p')
		return (ptf_puttype_p(pt, ap));
	else if (pt->type == 'n')
		return (ptf_puttype_n(*print_len, ap));
	return (PTF_ERROR);
}

static int		ptf_print(const char *format, va_list ap, int *print_len)
{
	int			parse_len;
	t_ptinfo	pt;
	int			res;

	if (*format != '%')
	{
		ptf_putcharn(*format, 1);
		*print_len += 1;
		return (1);
	}
	ptf_init_info(&pt);
	parse_len = ptf_parse(format, &pt, ap);
	res = ptf_puttype(&pt, ap, print_len);
	if (res == PTF_ERROR)
		return (res);
	*print_len += pt.print_size;
	return (parse_len);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	fmt_len;
	int		parse_len;
	int		print_len;

	if (!format)
		return (0);
	fmt_len = 0;
	print_len = 0;
	va_start(ap, format);
	while (*(format + fmt_len))
	{
		parse_len = ptf_print(format + fmt_len, ap, &print_len);
		if (parse_len == PTF_ERROR)
			return (0);
		fmt_len += parse_len;
	}
	va_end(ap);
	return (print_len);
}
