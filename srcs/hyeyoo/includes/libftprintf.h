/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 01:52:48 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/04/10 12:07:35 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# define FLAG_MINUS			1
# define FLAG_PLUS			2
# define FLAG_SPACE			4
# define FLAG_SHARP			8
# define FLAG_ZERO			16
# define DEFAULT_PRECISION	-1
# define DEFAULT_WIDTH		-1
# define PTR_NULL			"0x0"
# define STR_NULL			"(null)"

typedef struct	s_format
{
	size_t		flag;
	int			width;
	int			precision;
	const char	*length;
	char		specifier;
}				t_format;

typedef struct	s_putnbr
{
	int		min_len;
	int		pad;
	int		minus;
	int		plus;
	int		zero;
	int		sharp;
	int		space;
	int		precision;
	int		width;
	char	*base;
	char	*prefix;
}				t_putnbr;

int				ft_format(t_format format, va_list ap);
int				ft_printf(const char *format, ...);
int				ft_cformat(t_format format, va_list ap);
int				ft_sformat(t_format format, va_list ap);
int				ft_dformat(t_format format, va_list ap);
int				ft_uformat(t_format format, va_list ap);
int				ft_pformat(t_format format, va_list ap);
int				ft_xformat(t_format format, va_list ap);
int				ft_lxformat(t_format format, va_list ap);
int				ft_putnbr_len(int64_t n, t_putnbr nbr);
int				ft_putnbr_base_len(uint64_t n, t_putnbr nbr);
int				ft_putnbr_unsigned_len(uint64_t n, t_putnbr nbr);
void			ft_init_putnbr(t_putnbr *nbr);
int				ft_fminus(t_format format);
int				ft_fplus(t_format format);
int				ft_fzero(t_format format);
int				ft_fspace(t_format format);
int				ft_fsharp(t_format format);

#endif
