/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_utf8.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:32:22 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:32:23 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_UTF8_H
# define T_UTF8_H

# define TWO_BYTES_MASK		0xffffff80
# define THREE_BYTES_MASK	0xfffff800
# define FOUR_BYTES_MASK	0xffff0000

# include <stdlib.h>
# include <wchar.h>

/*
**	stdlib.h
**		size_t
**
**	wchar.h
**		wchar_t
*/

typedef struct		s_utf8
{
	unsigned int	data;
	size_t			len;
}					t_utf8;

char				*cpyutf8tos(char *des, t_utf8 *src);
t_utf8				wctoutf8(wchar_t wc);
char				*wstoutf8s(const wchar_t *ws);

#endif
