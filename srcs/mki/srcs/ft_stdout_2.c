/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:11:50 by mki               #+#    #+#             */
/*   Updated: 2020/11/12 10:43:37 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_width_1_process(t_var *sv)
{
	if (sv->width_flag == ON)
	{
		if (sv->width_len < 0)
		{
			sv->left_flag = ON;
			sv->width_len *= -1;
			sv->zero_flag = OFF;
		}
		if (sv->width_len - sv->value_len - sv->r_preci_len > 0)
		{
			sv->r_width_len = sv->width_len - sv->value_len - sv->r_preci_len;
			sv->r_width_len -= sv->minus_len;
		}
	}
}

void	ft_width_2_process(t_var *sv)
{
	if (sv->zero_flag == ON && sv->left_flag == ON)
		sv->zero_flag = OFF;
	if (sv->preci_flag == ON && sv->preci_len == 0 && sv->value == 0)
	{
		if (sv->type != 'p' && sv->type != 'c' && sv->type != '%')
		{
			if (sv->type != 's')
			{
				sv->value_len = 0;
				if (sv->width_len > 0)
					sv->r_width_len++;
			}
		}
	}
}

void	ft_stdout(t_var *sv)
{
	if (sv->left_flag == OFF)
	{
		ft_width_print(sv);
		ft_preci_print(sv);
		ft_value_print(sv);
	}
	else if (sv->left_flag == ON)
	{
		ft_preci_print(sv);
		ft_value_print(sv);
		ft_width_print(sv);
	}
}
