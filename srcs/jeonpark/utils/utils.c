/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:33:15 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:33:16 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "utils.h"
#include "libft.h"

/*
**	stddef.h
**		size_t
*/

void	pad_char(char **ptr, char c, size_t padding_size)
{
	ft_memset(*ptr, c, padding_size);
	*ptr += padding_size;
}
