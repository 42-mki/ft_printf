/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:21:22 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/03/17 12:25:53 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_fsharp(t_format format)
{
	return (format.flag & FLAG_SHARP);
}

int	ft_fspace(t_format format)
{
	return (format.flag & FLAG_SPACE);
}

int	ft_fminus(t_format format)
{
	return (format.flag & FLAG_MINUS);
}

int	ft_fzero(t_format format)
{
	return (format.flag & FLAG_ZERO);
}

int	ft_fplus(t_format format)
{
	return (format.flag & FLAG_PLUS);
}
