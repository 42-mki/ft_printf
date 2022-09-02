/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 05:31:50 by mki               #+#    #+#             */
/*   Updated: 2020/11/04 17:30:03 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s) + 1;
	ret = (char *)ft_memchr(s, c, len);
	return (ret);
}
