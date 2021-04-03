/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:37:14 by mki               #+#    #+#             */
/*   Updated: 2020/11/12 13:25:54 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_var	sv;

	va_start(ap, format);
	sv.ret = 0;
	while (*format)
	{
		if (*format != '%' && *format)
			sv.ret += ft_putchar(*format++);
		else
		{
			++format;
			ft_sv_init(&sv);
			ft_flag_check(&(format), &sv, &ap);
			ft_process(&ap, &sv);
		}
	}
	va_end(ap);
	return (sv.ret);
}
