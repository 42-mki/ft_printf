/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:28:32 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 12:28:59 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

size_t	ptf_putcharn(const char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(STDOUT_FILENO, &c, 1);
		i++;
	}
	return (i);
}

size_t	ptf_putstr(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
	{
		write(STDOUT_FILENO, s + i, 1);
		i++;
	}
	return (i);
}

size_t	ptf_putnstr(const char *s, int n)
{
	ssize_t	i;

	if (!s)
		return (0);
	i = 0;
	while (i < n && *(s + i))
	{
		write(STDOUT_FILENO, s + i, 1);
		i++;
	}
	return (i);
}
