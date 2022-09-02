/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 02:53:49 by jayun             #+#    #+#             */
/*   Updated: 2020/10/01 02:58:41 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	int		i;

	temp = 0;
	if (s != 0)
	{
		temp = (char *)malloc(sizeof(char) * (len + 1));
		if (temp == 0)
			return (0);
		i = 0;
		while ((unsigned long)i < len)
		{
			if (s[start + i] == '\0' || (start + i) >= ft_strlen(s))
				break ;
			temp[i] = s[start + i];
			i++;
		}
		temp[i] = '\0';
	}
	return (temp);
}
