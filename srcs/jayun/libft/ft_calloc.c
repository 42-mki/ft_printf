/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 02:44:53 by jayun             #+#    #+#             */
/*   Updated: 2020/10/01 02:45:04 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	int		i;

	temp = (void *)malloc(count * size);
	if (temp == 0)
		return (0);
	i = 0;
	while (i < (int)(count * size))
	{
		*(char *)(temp + i) = 0;
		i++;
	}
	return (temp);
}
