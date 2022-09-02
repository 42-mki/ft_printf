/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:38:33 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/10 11:59:18 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_nbr_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	n_len;
	size_t	i;

	n_len = ft_nbr_len(n);
	if ((s = (char*)malloc(sizeof(char) * (n_len + 1))) == NULL)
		return (NULL);
	i = 0;
	ft_putnbr_buf(n, s, &i);
	return (s);
}
