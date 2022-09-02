/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:05:34 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 14:12:20 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

void	validate_specifier(t_ptinfo *pt)
{
	if ((pt->props & (1 << PTF_FLAG_LEFT))
		&& (pt->props & (1 << PTF_FLAG_ZERO)))
		pt->props &= ~(1 << PTF_FLAG_ZERO);
	if ((pt->props & (1 << PTF_FLAG_PLUS))
		&& (pt->props & (1 << PTF_FLAG_EMPTY)))
		pt->props &= ~(1 << PTF_FLAG_EMPTY);
}
