/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:31:03 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:31:04 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "convert.h"
#include "t_spec.h"
#include "libft.h"

/*
**	stdarg
**		va_arg()
*/

int			convert_n(t_spec *spec)
{
	void	*n;

	n = va_arg(spec->ap, void *);
	if (get_flag(spec, IS_LENGTH_LL))
		*(long long *)n = spec->num_of_char_printed;
	else if (get_flag(spec, IS_LENGTH_L))
		*(long *)n = spec->num_of_char_printed;
	else if (get_flag(spec, IS_LENGTH_HH))
		*(signed char *)n = spec->num_of_char_printed;
	else if (get_flag(spec, IS_LENGTH_HH))
		*(signed char *)n = spec->num_of_char_printed;
	else if (get_flag(spec, IS_LENGTH_H))
		*(short *)n = spec->num_of_char_printed;
	else
		*(int *)n = spec->num_of_char_printed;
	return (0);
}
