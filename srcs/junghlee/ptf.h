/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:46:57 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 22:02:13 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTF_H
# define PTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

/*
** Re-define long type name to short type name
*/

typedef unsigned long long	t_ull;
typedef long long			t_ll;
typedef unsigned int		t_uint;

/*
** Return value
*/
# define PTF_ERROR -1
# define PTF_SUCCESS 1
# define PTF_RETURN_SIZE -2

/*
** Format(flag, length)
*/

# define PTF_FLAG_LEFT 0
# define PTF_FLAG_ZERO 1
# define PTF_FLAG_SHARP 2
# define PTF_FLAG_EMPTY 3
# define PTF_FLAG_PLUS 4
# define PTF_LENGTH_HH 5
# define PTF_LENGTH_H 6
# define PTF_LENGTH_L 7
# define PTF_LENGTH_LL 8
# define PTF_NEGATIVE 9

/*
** Struct for storing printf info
**
** flag(left, zero) -> T/F
** length(hh, h, l, ll) -> T/F
** width -> int
** precision -> int
** type -> char
*/

typedef struct	s_ptinfo
{
	t_ll	props;
	char	type;
	int		width;
	int		precision;
	int		zero;
	int		space;
	int		print_size;
}				t_ptinfo;

/*
** Main function
** - main.c
*/

int				ft_printf(const char *format, ...);

/*
** Parse function
** - parse.c
** - utils_parse.c
*/

size_t			ptf_parse_flag(const char *format, t_ptinfo *pt);

size_t			ptf_parse_width(const char *format,
								t_ptinfo *pt, va_list ap);

size_t			ptf_parse_precision(const char *format,
									t_ptinfo *pt, va_list ap);

size_t			ptf_parse_length(const char *format, t_ptinfo *pt);

size_t			ptf_parse_type(const char *format, t_ptinfo *pt);

void			validate_specifier(t_ptinfo *pt);

/*
** Put type function
** - puttype_c.c
** - puttype_di.c
** - puttype_n.c
** - puttype_p.c
** - puttype_percent.c
** - puttype_s.c
** - puttype_uox.c
*/

int				ptf_puttype_c(t_ptinfo *pt, va_list ap);

int				ptf_puttype_di(t_ptinfo *pt, va_list ap);

int				ptf_puttype_n(int total_print_len, va_list ap);

int				ptf_puttype_p(t_ptinfo *pt, va_list ap);

int				ptf_puttype_percent(t_ptinfo *pt);

int				ptf_puttype_s(t_ptinfo *pt, va_list ap);

int				ptf_puttype_uox(t_ptinfo *pt, va_list ap);

/*
** Utility function
** - utils_char_string.c
** - utils_number.c
** - utils_type.c
*/

size_t			ptf_putcharn(const char c, int n);

size_t			ptf_putstr(const char *s);

size_t			ptf_putnstr(const char *s, int n);

int				ptf_atoi(const char *str, size_t *digit_len);

char			*ptf_ulltoa(t_ptinfo *pt, t_ull n,
							t_ull base, char *base_set);

int				ptf_isspace(int c);

int				ptf_isdigit(int c);

int				ptf_istype(const char *c);

#endif
