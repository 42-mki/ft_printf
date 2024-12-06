/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:23:00 by mki               #+#    #+#             */
/*   Updated: 2020/11/07 14:51:39 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_width_check(const char **format, t_var *sv, va_list *ap)
{
	int		len;
	char	*tmp;

	len = 0;
	if (ft_isdigit(**format))
	{
		sv->width_flag = ON;
		while (ft_isdigit((*format)[len]))
			len++;
		tmp = ft_substr(*format, 0, len);
		*format += len;
		sv->width_len = ft_atoi(tmp);
		free(tmp);
	}
	else if (**format == '*' && *(*format - 1) != '.')
	{
		sv->width_flag = ON;
		sv->width_len = va_arg(*ap, int);
		(*format)++;
	}
}

void	ft_preci_check(const char **format, t_var *sv, va_list *ap)
{
	int		len;
	char	*tmp;

	len = 0;
	if (ft_isdigit(**format))
	{
		sv->preci_flag = ON;
		while (ft_isdigit((*format)[len]))
			len++;
		tmp = ft_substr(*format, 0, len);
		*format += len;
		sv->preci_len = ft_atoi(tmp);
		free(tmp);
	}
	else if (**format == '*' && *(*format - 1) == '.')
	{
		sv->preci_flag = ON;
		sv->preci_len = va_arg(*ap, int);
		(*format)++;
	}
}
