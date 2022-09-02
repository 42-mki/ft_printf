/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 05:54:48 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/03/22 02:44:01 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>
#include "libft.h"

size_t	ft_nbrlen_base(int64_t n, int base)
{
	size_t		len;

	if (n == 0)
		return (1);
	len = 0;
	while (ft_abs(n) > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}
