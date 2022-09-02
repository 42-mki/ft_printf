/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 03:41:35 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/09 13:14:05 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "libftprintf.h"

size_t		ft_flag(const char **format)
{
	size_t	flag;

	flag = 0;
	while (1)
	{
		if (**format == '-')
			flag |= FLAG_MINUS;
		else if (**format == '+')
			flag |= FLAG_PLUS;
		else if (**format == ' ')
			flag |= FLAG_SPACE;
		else if (**format == '#')
			flag |= FLAG_SHARP;
		else if (**format == '0')
			flag |= FLAG_ZERO;
		else
			break ;
		(*format)++;
	}
	return (flag);
}

int			ft_width(const char **format, va_list ap, t_format *form)
{
	int	width;

	if (**format == '*')
	{
		width = va_arg(ap, int);
		(*format)++;
	}
	else
	{
		width = ft_atoi(*format);
		if (!ft_isdigit(**format))
			return (DEFAULT_WIDTH);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (width < 0)
	{
		width = ft_abs(width);
		form->flag |= FLAG_MINUS;
	}
	return (width);
}

const char	*ft_length(const char **format)
{
	const char	*length;
	int			len;
	char		c;

	length = *format;
	len = 0;
	while (1)
	{
		c = (*format)[len];
		if (c == 'c' || c == 's' || c == 'p' || c == 'd')
			break ;
		else if (c == 'i' || c == 'u' || c == 'x' || c == 'X')
			break ;
		else if (c == '%')
			break ;
		len++;
	}
	length = ft_strldup(*format, len + 1);
	(*format) = (*format) + len;
	return (length);
}

int			ft_precision(const char **format, va_list ap)
{
	int	precision;

	if (**format != '.')
		return (DEFAULT_PRECISION);
	else
	{
		(*format)++;
		if (**format == '*')
		{
			precision = va_arg(ap, int);
			(*format)++;
		}
		else
		{
			precision = ft_atoi(*format);
			if (!ft_isdigit(**format))
				return (0);
			while (ft_isdigit(**format))
				(*format)++;
		}
		if (precision < 0)
			precision = DEFAULT_PRECISION;
		return (precision);
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	form;
	int			ret;

	ret = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			ret++;
			format++;
			continue;
		}
		format++;
		form.flag = ft_flag(&format);
		form.width = ft_width(&format, ap, &form);
		form.precision = ft_precision(&format, ap);
		form.length = ft_length(&format);
		form.specifier = *(format++);
		ret += ft_format(form, ap);
		free((char*)form.length);
	}
	return (ret);
}
