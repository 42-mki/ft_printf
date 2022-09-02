/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:11:31 by mki               #+#    #+#             */
/*   Updated: 2020/11/04 17:31:26 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *tmp_s1;
	unsigned char *tmp_s2;

	if (n == 0)
		return (0);
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (--n)
	{
		if ((unsigned char)*tmp_s1 != (unsigned char)*tmp_s2)
			break ;
		tmp_s1++;
		tmp_s2++;
	}
	return (*tmp_s1 - *tmp_s2);
}
