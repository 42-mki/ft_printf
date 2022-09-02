/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:02:55 by seoh              #+#    #+#             */
/*   Updated: 2020/09/25 02:36:07 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_sc(va_list ap, t_struct *strt)
{
	char	*data_s;
	int		data_c;

	data_s = 0;
	data_c = 0;
	if (strt->spec == 's')
		data_s = va_arg(ap, char *);
	else if (strt->spec == 'c')
		data_c = va_arg(ap, int);
	else
		data_c = '%';
	data_s = (data_s == NULL) ? "(null)" : data_s;
	strt->data_len = (strt->spec == 's') ? ft_strlen_pft(data_s, strt) : 1;
	strt->align == 0 ? print_space_sc(strt) : 0;
	print_zero_sc(strt);
	strt->spec == 's' ? ft_putstr(data_s, strt) : ft_putchar(data_c, strt);
	strt->align == 1 ? print_space_sc(strt) : 0;
}

void		print_space_sc(t_struct *strt)
{
	int		i;

	if (strt->zero && !strt->align && !strt->dot && !strt->prec)
		return ;
	i = 0;
	if (strt->prec && strt->prec < strt->data_len)
		while (i++ < (strt->width - strt->prec))
			ft_putchar(' ', strt);
	else if (!strt->zero && strt->data_len < strt->width)
		while (i++ < (strt->width - strt->data_len))
			ft_putchar(' ', strt);
}

void		print_zero_sc(t_struct *strt)
{
	int		i;

	i = 0;
	if (strt->zero && !strt->align)
		while (i++ < strt->width - strt->data_len)
			ft_putchar('0', strt);
}
