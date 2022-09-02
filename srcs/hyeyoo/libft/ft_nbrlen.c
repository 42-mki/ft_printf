/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 01:22:54 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/03/22 02:43:50 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>
#include "libft.h"

size_t	ft_nbrlen(int64_t nbr)
{
	size_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (ft_abs(nbr) > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
