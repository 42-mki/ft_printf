/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 02:05:23 by seoh              #+#    #+#             */
/*   Updated: 2020/09/25 04:42:22 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

/*
** #include "./libft/libft.h" : LIBFT 사용시.. (utils 추가 시 삭제)
*/

# define DEC "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct  s_struct
{
	int	input_len;
	int	width;
	int	len;
	int	align;
	int	dot;
	int	prec;
	int	spec;
	int zero;
	int rtn;
	int data_len;
}               t_struct;

/*
** void	print_struct(t_struct *strt); : 테스트용 구조체 전체 출력
*/

/*
** ft_printf.c
*/

int		ft_printf(const char *input, ...);
void	init_struct(t_struct *strt);
void	main_process(va_list ap, const char *input, t_struct *strt);

/*
** ft_printf_parser.c
*/

void	parse_flags(const char **input, t_struct *strt);
void	parse_width(const char **input, t_struct *strt, va_list ap);
void	parse_precision(const char **input, t_struct *strt, va_list ap);
void	parse_specifier(const char **input, t_struct *strt);

/*
** ft_printf_diu....c
*/

void	printer(va_list ap, t_struct *strt);
void	print_diu(va_list ap, t_struct *strt);
void	print_space_diuxp(t_struct *strt, long long data);
void	print_zero_diuxp(t_struct *strt, long long data);

/*
** ft_printf_sc....c
*/

void	print_sc(va_list ap, t_struct *strt);
void	print_space_sc(t_struct *strt);
void	print_zero_sc(t_struct *strt);

/*
** UTILITIES
*/

void	ft_putchar(const char c, t_struct *strt);
void	ft_putstr(const char *s, t_struct *strt);
void	ft_putnbr_base(long long n, char *base, t_struct *strt);
int		ft_strlen_pft(const char *str, t_struct *strt);
int		ft_nbrlen_base(long long n, char *base, t_struct *strt);

#endif