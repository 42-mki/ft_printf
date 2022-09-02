/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_svar_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:47:17 by mki               #+#    #+#             */
/*   Updated: 2020/11/11 13:25:47 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_sv_init(t_var *sv)
{
	sv->zero_flag = OFF;
	sv->left_flag = OFF;
	sv->width_flag = OFF;
	sv->width_len = OFF;
	sv->preci_flag = OFF;
	sv->preci_len = OFF;
	sv->p_flag = OFF;
	sv->value = OFF;
	sv->value_len = OFF;
	sv->minus = OFF;
	sv->minus_len = OFF;
	sv->r_width_len = OFF;
	sv->r_preci_len = OFF;
	sv->type = OFF;
	sv->digit = "0123456789";
	sv->lowcase = "0123456789abcdef";
	sv->upcase = "0123456789ABCDEF";
}
