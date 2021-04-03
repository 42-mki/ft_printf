/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:11:50 by mki               #+#    #+#             */
/*   Updated: 2020/11/11 14:06:35 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process(va_list *ap, t_var *sv)
{
	ft_arg_process(ap, sv);
	ft_value_process(sv);
	ft_preci_process(sv);
	ft_width_1_process(sv);
	ft_width_2_process(sv);
	sv->ret += sv->r_preci_len;
	sv->ret += sv->value_len;
	sv->ret += sv->r_width_len;
	ft_stdout(sv);
}

void	ft_arg_process(va_list *ap, t_var *sv)
{
	if (sv->type == 'd' || sv->type == 'i')
		sv->value = va_arg(*ap, int);
	else if (sv->type == 'u' || sv->type == 'x' || sv->type == 'X')
		sv->value = va_arg(*ap, unsigned int);
	else if (sv->type == 'p')
	{
		sv->value = va_arg(*ap, long long);
		sv->p_flag = ON;
	}
	else if (sv->type == 'c')
		sv->value_char = va_arg(*ap, int);
	else if (sv->type == '%')
		sv->value_char = '%';
	else if (sv->type == 's')
		sv->value_str = va_arg(*ap, char *);
}

void	ft_value_process(t_var *sv)
{
	sv->minus = sv->value < 0 ? 1 : 0;
	sv->minus_len = sv->minus;
	sv->value = sv->value >= 0 ? sv->value : -sv->value;
	if (sv->type == 'd' || sv->type == 'i' || sv->type == 'u')
		sv->value_len = ft_numlen(sv->value, 10);
	else if (sv->type == 'x' || sv->type == 'X')
		sv->value_len = ft_numlen(sv->value, 16);
	else if (sv->type == 'p')
	{
		sv->value_len = ft_numlen(sv->value, 16);
		if (sv->type == 'p' && sv->preci_flag == ON && sv->preci_len == 0)
			if (sv->value == 0)
				sv->value_len = 0;
		sv->value_len += 2;
	}
	else if (sv->type == 'c' || sv->type == '%')
		sv->value_len = 1;
	else if (sv->type == 's')
		sv->value_len = ft_strlen(sv->value_str);
}

void	ft_preci_process(t_var *sv)
{
	if (sv->preci_len < 0)
		sv->preci_flag = OFF;
	if (sv->preci_flag == ON && sv->preci_len > sv->value_len)
	{
		sv->r_preci_len = sv->preci_len - sv->value_len;
		if (sv->type == 'p')
			sv->r_preci_len += 2;
		else if (sv->type == 's')
			sv->r_preci_len = 0;
	}
	else if (sv->preci_flag == ON && sv->preci_len <= sv->value_len)
		if (sv->type == 's')
			sv->value_len = sv->preci_len;
	if (sv->type == '%')
	{
		sv->preci_flag = OFF;
		sv->r_preci_len = 0;
	}
}
