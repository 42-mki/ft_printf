/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:30:42 by jeonpark          #+#    #+#             */
/*   Updated: 2021/03/23 13:30:43 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "t_spec.h"

int	convert_c(t_spec *spec);
int	convert_dioux(t_spec *spec);
int	convert_n(t_spec *spec);
int	convert_p(t_spec *spec);
int	convert_percent(t_spec *spec);
int	convert_s(t_spec *spec);

#endif
