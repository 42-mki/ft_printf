/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:11:50 by mki               #+#    #+#             */
/*   Updated: 2020/11/11 11:45:32 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_value_print(t_var *sv)
{
	ft_p_print(sv);
	if (sv->type == 'c' || sv->type == '%')
		write(1, &sv->value_char, 1);
	if (!(sv->preci_flag == ON && sv->preci_len == 0 && sv->value == 0))
	{
		if (sv->value_len > 0)
		{
			ft_minus_print(sv);
			if (sv->type == 'd' || sv->type == 'i' || sv->type == 'u')
				ft_putnbr_base(sv->value, 10, sv->digit);
			else if (sv->type == 'x')
				ft_putnbr_base(sv->value, 16, sv->lowcase);
			else if (sv->type == 'X')
				ft_putnbr_base(sv->value, 16, sv->upcase);
			else if (sv->type == 'p')
				ft_putnbr_base(sv->value, 16, sv->lowcase);
			else if (sv->type == 's')
				ft_putstr_fd(sv->value_str, 1, sv->value_len);
		}
	}
}

void	ft_preci_print(t_var *sv)
{
	if (sv->preci_flag == ON)
	{
		ft_minus_print(sv);
		ft_p_print(sv);
	}
	while ((sv->r_preci_len)-- > 0)
		write(1, "0", 1);
}

void	ft_width_print(t_var *sv)
{
	if (sv->width_len > sv->value_len)
	{
		if (sv->zero_flag == ON && sv->preci_flag == OFF)
		{
			ft_minus_print(sv);
			ft_p_print(sv);
			while ((sv->r_width_len)-- > 0)
				write(1, "0", 1);
		}
		else if (sv->zero_flag == OFF || sv->preci_flag == ON)
			while ((sv->r_width_len)-- > 0)
				write(1, " ", 1);
	}
}

void	ft_minus_print(t_var *sv)
{
	if (sv->minus == ON)
	{
		write(1, "-", 1);
		sv->ret++;
		sv->minus = OFF;
	}
}

void	ft_p_print(t_var *sv)
{
	if (sv->p_flag == ON)
	{
		write(1, "0x", 2);
		sv->p_flag = OFF;
	}
}
