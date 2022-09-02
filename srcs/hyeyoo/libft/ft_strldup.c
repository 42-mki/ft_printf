/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:59:17 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/03/12 15:00:05 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strldup(const char *str, size_t len)
{
	char	*copied;

	copied = (char*)malloc(sizeof(char) * (len));
	ft_strlcpy(copied, str, len);
	return (copied);
}
