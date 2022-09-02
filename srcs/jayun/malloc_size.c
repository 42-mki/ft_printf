/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 01:09:21 by jayun             #+#    #+#             */
/*   Updated: 2020/10/26 01:10:09 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*malloc_size(int size)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == 0)
	{
		g_malloc_error = -1;
		return (0);
	}
	result[size] = '\0';
	while (size--)
		result[size] = 32;
	return (result);
}
