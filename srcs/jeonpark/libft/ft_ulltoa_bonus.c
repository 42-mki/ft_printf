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
**		malloc()
*/

/*
**	Assume sizeof(long long) == 8
**		-> MAX_LEN == 19
*/

#define MAX_LEN 19

char	*ft_ulltoa(unsigned long long n)
{
	char			tmp[MAX_LEN];
	char			*p_tmp;
	char			*result;
	char			*p_result;

	p_tmp = tmp;
	*p_tmp++ = '0' + n % 10;
	while ((n /= 10))
		*p_tmp++ = '0' + n % 10;
	if (!(result = malloc(sizeof(*result) * ((p_tmp - tmp) + 1))))
		return (0);
	p_result = result;
	while (tmp != p_tmp)
		*p_result++ = *(--p_tmp);
	*p_result = '\0';
	return (result);
}
