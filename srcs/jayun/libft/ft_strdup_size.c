/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 05:50:15 by jayun             #+#    #+#             */
/*   Updated: 2020/10/16 05:54:16 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_size(const char *s1, int size)
{
	int		i;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (size + 1));
	if (temp == 0)
		return (0);
	temp[size] = '\0';
	i = 0;
	while (i < size)
	{
		temp[i] = s1[i];
		i++;
	}
	return (temp);
}
