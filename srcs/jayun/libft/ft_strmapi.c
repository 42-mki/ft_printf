/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 02:52:11 by jayun             #+#    #+#             */
/*   Updated: 2020/10/01 02:52:13 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*temp;

	temp = 0;
	if (s != 0)
	{
		len = ft_strlen(s);
		i = 0;
		temp = (char *)malloc(sizeof(char) * (len + 1));
		if (temp == 0)
			return (0);
		temp[len] = '\0';
		while (i < len)
		{
			temp[i] = f(i, s[i]);
			i++;
		}
	}
	return (temp);
}
