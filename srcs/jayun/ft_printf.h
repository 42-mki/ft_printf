/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:09:54 by jayun             #+#    #+#             */
/*   Updated: 2020/10/27 17:52:15 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

va_list	g_ap;
char	*g_total_result;
int		g_total_len;
int		g_malloc_error;
int		g_minus;
int		g_zero;
int		g_width;
int		g_pre;
int		g_plus;
int		g_space;
int		g_sharp;
int		g_prime;
int		g_width_num;
int		g_pre_num;
typedef union	u_double
{
	double		double_value;
	struct
	{
		size_t	mantissa : 52;
		size_t	exponent : 11;
		size_t	sign : 1;
	}			s_int;
	size_t		total_value;
}				t_double;
int				ft_printf(const char *str, ...);
void			option_check(const char *str, int left, int right);
char			*malloc_size(int size);
void			add_result(char *str, int size);
void			add_result2(char c);
void			right_write_dui(char *num, char type);
void			left_write_dui(char *num, char type);
int				type_dui(const char *str, int left, int right);
void			right_write_perandc(char *c);
void			left_write_perandc(char *c);
int				type_perandc(const char *str, int left, int right);
void			right_write_s(char *str);
void			left_write_s(char *str);
int				type_s(const char *str, int left, int right);
void			right_write_p(char *addr);
void			left_write_p(char *addr);
int				type_p(const char *str, int left, int right);
void			right_write_xo(char *num, char type, unsigned int n);
void			left_write_xo(char *num, char type, unsigned int n);
char			*get_basenum(unsigned int n, char type);
int				type_xo(const char *str, int left, int right);
void			bankers_rounding(char **num, char **result, int n);
int				number_place_check(char *num);
int				dot_place_check(char *num);
int				type_n(const char *str, int left, int right);
int				get_size_f(char *num);
void			zero_sign_f_r(char *num, char **result, int *i);
void			right_write_f(char *num);
void			pre_f_l(char *num, char **result, int *i, int j);
void			sign_getdotj_f_l(char *num, char **result, int *i, int *j);
void			left_write_f(char *num);
int				get_llsize(long long n);
char			*ft_lltoa(long long n, int minus);
int				ft_dtoa2(double n, long long int_part, char **result);
char			*ft_dtoa(double n);
void			rounding_check_f(char **num);
int				type_f(const char *str, int left, int right);
int				get_size_e(char *num);
int				index_e_r(char **result, int e, int *i);
void			right_write_e(char *num, int e);
int				index_e_l(char **result, int e, int i);
void			left_write_e(char *num, int e);
char			*ft_dtoa_e(double n, int *e);
void			rounding_check_e(char **num, int *e);
int				type_e(const char *str, int left, int right);
int				get_size_g(char *num);
int				get_size_gf(char *num, int z);
void			right_write_gf(char *num, int z);
void			left_write_gf(char *num, int z);
void			right_write_ge(char *num, int e);
void			left_write_ge(char *num, int e);
void			rounding_check_gf(char **num);
void			rounding_check_ge(char **num, int *e);
int				type_g(const char *str, int left, int right);
int				type_hh(const char *str, int left, int *right);
int				type_h(const char *str, int left, int *right);
char			*ft_lltoa_u(unsigned long long n, int minus);
char			*get_basenum_ll(unsigned long long n, char type);
int				type_l(const char *str, int left, int *right);
int				type_ll(const char *str, int left, int *right);

#endif
