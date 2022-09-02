/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:37:26 by mki               #+#    #+#             */
/*   Updated: 2020/11/12 10:44:27 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define SUCCESS	0
# define FAIL		1
# define ERROR		-1

# define INIT		0
# define OFF		0
# define ON			1

# define INT		1
# define DOUBLE		2
# define POINTER	3

# define TYPE		"cspdiuxX%"
# define BASE_10	"0123456789"
# define LOWCASE    "0123456789abcdef"
# define UPCASE		"0123456789ABCDEF"

typedef struct	s_var
{
	int			zero_flag;
	int			left_flag;

	int			width_flag;
	int			width_len;

	int			preci_flag;
	int			preci_len;

	int			p_flag;

	long long	value;
	int			value_char;
	char		*value_str;
	int			value_len;
	int			minus;
	int			minus_len;
	int			r_width_len;
	int			r_preci_len;

	char		type;
	char		*digit;
	char		*lowcase;
	char		*upcase;

	int			ret;
}				t_var;

/*
** srcs
*/

void			ft_flag_check(const char **format, t_var *sv, va_list *ap);
void			ft_zero_left_check(const char **format, t_var *sv);
void			ft_dot_check(const char **format, t_var *sv);
void			ft_type_check(const char **format, t_var *sv);
void			ft_width_check(const char **format, t_var *sv, va_list *ap);
void			ft_preci_check(const char **format, t_var *sv, va_list *ap);
int				ft_printf(const char *f, ...);
void			ft_process(va_list *ap, t_var *sv);
void			ft_arg_process(va_list *ap, t_var *sv);
void			ft_value_process(t_var *sv);
void			ft_preci_process(t_var *sv);
void			ft_width_1_process(t_var *sv);
void			ft_width_2_process(t_var *sv);
void			ft_stdout(t_var *sv);
void			ft_value_print(t_var *sv);
void			ft_preci_print(t_var *sv);
void			ft_width_print(t_var *sv);
void			ft_minus_print(t_var *sv);
void			ft_p_print(t_var *sv);
void			ft_sv_init(t_var *sv);

/*
** libft
*/

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_istype(char c);
int				ft_iswidth(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
int				ft_numlen(long long n, int base_num);
int				ft_putchar(char c);
void			ft_putnbr_base(long long n, int base_num, char *base);
void			ft_putstr_fd(char *s, int fd, int len);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, char *needle, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
