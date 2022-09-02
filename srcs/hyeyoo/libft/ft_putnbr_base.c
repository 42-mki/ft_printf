/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 06:03:49 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/10 12:03:22 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_is_valid(char *str)
{
	int	len;
	int	count[256];
	int	i;

	i = 0;
	while (i < 256)
	{
		count[i] = 0;
		i++;
	}
	len = ft_strlen(str);
	if (len <= 1)
		return (0);
	while (*str != '\0')
	{
		if (!(32 <= *str && *str <= 126))
			return (0);
		if (count[(int)*str] > 0)
			return (0);
		if (*str == '-' || *str == '+')
			return (0);
		count[(int)*str]++;
		str++;
	}
	return (1);
}

void		ft_putnbr_base(int64_t nbr, char *base)
{
	int len;

	if (!ft_is_valid(base))
		return ;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr / len != 0)
			ft_putnbr_base(-(nbr / len), base);
		ft_putchar(base[-(nbr % len)]);
	}
	else
	{
		if (nbr < len)
		{
			ft_putchar(base[nbr]);
		}
		else
		{
			ft_putnbr_base(nbr / len, base);
			ft_putchar(base[nbr % len]);
		}
	}
}
