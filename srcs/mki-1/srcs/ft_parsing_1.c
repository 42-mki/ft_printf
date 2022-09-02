/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:22:28 by mki               #+#    #+#             */
/*   Updated: 2020/11/14 14:22:46 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flag_check(const char **format, t_var *sv, va_list *ap)
{
	ft_zero_left_check(format, sv);
	ft_width_check(format, sv, ap);
	ft_dot_check(format, sv);
	ft_preci_check(format, sv, ap);
	ft_type_check(format, sv);
}

void	ft_zero_left_check(const char **format, t_var *sv)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			sv->left_flag = ON;
		if (**format == '0')
			sv->zero_flag = ON;
		++(*format);
	}
}

void	ft_dot_check(const char **format, t_var *sv)
{
	if (**format == '.')
	{
		sv->preci_flag = ON;
		++(*format);
	}
}

void	ft_type_check(const char **format, t_var *sv)
{
	if (ft_istype(**format))
	{
		sv->type = **format;
		++(*format);
	}
}
