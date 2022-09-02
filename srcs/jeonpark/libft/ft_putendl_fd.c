/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:56:47 by jeonpark          #+#    #+#             */
/*   Updated: 2021/01/03 17:56:48 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
**	unistd.h
**		write()
*/

void	ft_putendl_fd(char *s, int fd)
{
	char	c;

	c = '\n';
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, &c, 1);
}
