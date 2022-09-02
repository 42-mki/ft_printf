/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:22:44 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 20:07:08 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	stdlib.h
**		malloc(), NULL
*/

#define MAX_INT_LEN 10

char	*ft_itoa(int n)
{
	unsigned int	positive_n;
	char			tmp[MAX_INT_LEN];
	char			*p_tmp;
	char			*result;
	char			*p_result;

	positive_n = (n < 0 ? -n : n);
	p_tmp = tmp;
	*p_tmp++ = '0' + positive_n % 10;
	while ((positive_n /= 10))
		*p_tmp++ = '0' + positive_n % 10;
	if (!(result = malloc(sizeof(*result) * ((n < 0) + (p_tmp - tmp) + 1))))
		return (NULL);
	p_result = result;
	if (n < 0)
		*p_result++ = '-';
	while (tmp != p_tmp)
		*p_result++ = *(--p_tmp);
	*p_result = '\0';
	return (result);
}
