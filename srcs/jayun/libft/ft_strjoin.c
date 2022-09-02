/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 02:51:17 by jayun             #+#    #+#             */
/*   Updated: 2020/10/01 02:51:18 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		len;
	int		len2;
	int		i;
	int		j;

	temp = 0;
	if (s1 != 0 && s2 != 0)
	{
		len = ft_strlen(s1);
		len2 = ft_strlen(s2);
		temp = (char *)malloc(sizeof(char) * (len + len2 + 1));
		if (temp == 0)
			return (0);
		temp[len + len2] = '\0';
		i = -1;
		while (++i < len)
			temp[i] = s1[i];
		j = -1;
		while ((++j + i) < (len + len2))
			temp[i + j] = s2[j];
	}
	return (temp);
}
