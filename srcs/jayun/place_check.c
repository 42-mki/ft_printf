/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:19:05 by jayun             #+#    #+#             */
/*   Updated: 2020/10/25 20:19:53 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	number_place_check(char *num)
{
	int	n;

	n = 0;
	while ((num[n] == '0' || num[n] == '.' || num[n] == '-') && num[n] != '\0')
		n++;
	return (n);
}

int	dot_place_check(char *num)
{
	int	n;

	n = 0;
	while (num[n] != '.' && num[n] != '\0')
		n++;
	return (n);
}
