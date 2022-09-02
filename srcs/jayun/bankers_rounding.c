/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bankers_rounding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:27:11 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 19:28:03 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	bankers_rounding(char **num, char **result, int n)
{
	int	m;
	int k;

	m = n + 1;
	while (((*num)[m] == '0' || (*num)[m] == '.') && (*num)[m] != '\0')
		m++;
	k = n - 1;
	if ((*num)[k] == '.')
		k--;
	if ((*num)[m] == '\0')
	{
		if ((*num)[k] % 2 == 1)
			(*result)[k]++;
	}
	else
		(*result)[k]++;
}
