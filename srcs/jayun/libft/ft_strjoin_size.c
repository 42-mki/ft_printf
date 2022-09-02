/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 05:51:47 by jayun             #+#    #+#             */
/*   Updated: 2020/10/16 05:53:12 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_size(char const *s1, char const *s2, int size1, int size2)
{
	char	*temp;
	int		i;
	int		j;

	temp = 0;
	if (s1 != 0 && s2 != 0)
	{
		temp = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
		if (temp == 0)
			return (0);
		temp[size1 + size2] = '\0';
		i = -1;
		while (++i < size1)
			temp[i] = s1[i];
		j = -1;
		while ((++j + i) < (size1 + size2))
			temp[i + j] = s2[j];
	}
	return (temp);
}
