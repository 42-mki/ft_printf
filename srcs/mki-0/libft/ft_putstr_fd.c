/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:11:36 by mki               #+#    #+#             */
/*   Updated: 2020/11/11 11:46:06 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int len)
{
	if (!s)
	{
		write(1, "(null)", len);
		return ;
	}
	if (fd < 0)
		return ;
	write(fd, s, len);
}
