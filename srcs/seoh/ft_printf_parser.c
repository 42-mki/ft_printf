/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 06:58:27 by seoh              #+#    #+#             */
/*   Updated: 2020/09/25 04:06:35 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char **input, t_struct *strt)
{
	while (**input == '-' || **input == '0')
	{
		if (**input == '-')
			strt->align = 1;
		if (**input == '0')
			strt->zero = 1;
		(*input)++;
	}
	if (strt->align && strt->zero)
		strt->zero = 0;
}

void	parse_width(const char **input, t_struct *strt, va_list ap)
{
	if (**input == '*')
	{
		strt->width = va_arg(ap, int);
		if (strt->width < 0)
		{
			if (strt->zero)
				strt->zero = 0;
			strt->width *= -1;
			strt->align = 1;
		}
		(*input)++;
	}
	while (**input >= '0' && **input <= '9')
	{
		strt->width = (strt->width * 10) + **input - '0';
		(*input)++;
	}
}

void	parse_precision(const char **input, t_struct *strt, va_list ap)
{
	if (**input == '.')
	{
		strt->dot = 1;
		(*input)++;
	}
	if (**input == '*')
	{
		strt->prec = va_arg(ap, int);
		if (strt->prec < 0)
		{
			strt->prec = 0;
			strt->dot = 0;
		}
		(*input)++;
	}
	while (**input >= '0' && **input <= '9')
	{
		strt->prec = (strt->prec * 10) + **input - '0';
		(*input)++;
	}
}

void	parse_specifier(const char **input, t_struct *strt)
{
	if (**input == 'c' || **input == 's' || **input == 'p' || **input == 'd' ||
		**input == 'i' || **input == 'u' || **input == 'x' || **input == 'X' ||
		**input == '%')
		strt->spec = **input;
	else
		return ;
	(*input)++;
}
