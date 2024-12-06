/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:30:46 by mki               #+#    #+#             */
/*   Updated: 2020/11/07 17:02:08 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_numlen(long long n, int base_num)
{
	size_t	ret;

	if (n > 0)
		ret = 0;
	else if (n < 0)
	{
		ret = 1;
		n *= -1;
	}
	else
		return (1);
	while (n)
	{
		ret++;
		n /= base_num;
	}
	return (ret);
}
