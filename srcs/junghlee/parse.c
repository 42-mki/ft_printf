/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:02:17 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 22:03:33 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

size_t	ptf_parse_flag(const char *format, t_ptinfo *pt)
{
	size_t	len;

	len = 0;
	while (*(format + len))
	{
		if (*(format + len) == '-')
			pt->props |= (1LL << PTF_FLAG_LEFT);
		else if (*(format + len) == '0')
			pt->props |= (1LL << PTF_FLAG_ZERO);
		else if (*(format + len) == '#')
			pt->props |= (1LL << PTF_FLAG_SHARP);
		else if (*(format + len) == ' ')
			pt->props |= (1LL << PTF_FLAG_EMPTY);
		else if (*(format + len) == '+')
			pt->props |= (1LL << PTF_FLAG_PLUS);
		else
			break ;
		len++;
	}
	validate_specifier(pt);
	return (len);
}

size_t	ptf_parse_width(const char *format, t_ptinfo *pt, va_list ap)
{
	size_t	parse_len;

	if (!(*format))
		return (0);
	if (*format == '*')
	{
		if ((pt->width = va_arg(ap, int)) < 0)
		{
			pt->width *= -1;
			pt->props |= (1 << PTF_FLAG_LEFT);
			pt->props &= ~(1 << PTF_FLAG_ZERO);
		}
		return (1);
	}
	parse_len = 0;
	pt->width = ptf_atoi(format, &parse_len);
	return (parse_len);
}

size_t	ptf_parse_precision(const char *format, t_ptinfo *pt, va_list ap)
{
	size_t	parse_len;

	if (!(*format) || *format != '.')
		return (0);
	if (*(format + 1) == '*')
	{
		pt->precision = va_arg(ap, int);
		return (2);
	}
	else if (ptf_isdigit(*(format + 1)))
	{
		parse_len = 1;
		pt->precision = ptf_atoi(format + 1, &parse_len);
		return (parse_len);
	}
	else
		pt->precision = 0;
	return (1);
}

size_t	ptf_parse_length(const char *format, t_ptinfo *pt)
{
	if (!(*format))
		return (0);
	if (*format == 'h')
	{
		if (*format == *(format + 1))
		{
			pt->props |= (1 << PTF_LENGTH_HH);
			return (2);
		}
		pt->props |= (1 << PTF_LENGTH_H);
		return (1);
	}
	else if (*format == 'l')
	{
		if (*format == *(format + 1))
		{
			pt->props |= (1 << PTF_LENGTH_LL);
			return (2);
		}
		pt->props |= (1 << PTF_LENGTH_L);
		return (1);
	}
	return (0);
}

size_t	ptf_parse_type(const char *format, t_ptinfo *pt)
{
	if (!(*format) || !ptf_istype(format))
		return (0);
	pt->type = *format;
	return (1);
}
