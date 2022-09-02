/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_size_t_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:57:53 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/28 13:57:55 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	stddef.h
**		size_t
*/

size_t	ft_big_size_t(size_t lhs, size_t rhs)
{
	return (lhs > rhs ? lhs : rhs);
}
