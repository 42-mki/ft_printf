/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diuxp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 06:58:27 by seoh              #+#    #+#             */
/*   Updated: 2020/09/25 04:14:58 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printer(va_list ap, t_struct *strt)
{
	if (strt->spec == 'd' || strt->spec == 'i' || strt->spec == 'u' ||
		strt->spec == 'x' || strt->spec == 'X' || strt->spec == 'p')
		print_diu(ap, strt);
	else if (strt->spec == 's' || strt->spec == 'c' || strt->spec == '%')
		print_sc(ap, strt);
}

void	print_diu(va_list ap, t_struct *strt)
{
	char		*base;
	long long	data;

	if (strt->spec == 'd' || strt->spec == 'i')
		data = va_arg(ap, int);
	else if (strt->spec == 'u' || strt->spec == 'x' || strt->spec == 'X')
		data = va_arg(ap, unsigned int);
	else
		data = va_arg(ap, unsigned long);
	if (strt->spec == 'd' || strt->spec == 'i' || strt->spec == 'u')
		base = DEC;
	else if (strt->spec == 'X')
		base = HEX_UPPER;
	else
		base = HEX_LOWER;
	strt->data_len = data < 0 ? ft_nbrlen_base(-1 * data, base, strt)
		: ft_nbrlen_base(data, base, strt);
	strt->align == 0 ? print_space_diuxp(strt, data) : 0;
	data < 0 ? ft_putchar('-', strt) : 0;
	strt->spec == 'p' ? ft_putstr("0x", strt) : 0;
	print_zero_diuxp(strt, data);
	data < 0 ? ft_putnbr_base(-1 * data, base, strt)
		: ft_putnbr_base(data, base, strt);
	strt->align == 1 ? print_space_diuxp(strt, data) : 0;
}

void	print_space_diuxp(t_struct *strt, long long data)
{
	int	i;

	i = data < 0 ? 1 : 0;
	if (strt->zero && !strt->dot && !strt->prec)
		i += (strt->width - strt->data_len);
	if (strt->spec == 'p')
		i += 2;
	if (strt->data_len < strt->prec)
		while (i++ < (strt->width - strt->prec))
			ft_putchar(' ', strt);
	else
		while (i++ < (strt->width - strt->data_len))
			ft_putchar(' ', strt);
}

void	print_zero_diuxp(t_struct *strt, long long data)
{
	int	i;

	if (strt->zero && !strt->dot && !strt->prec)
	{
		i = data < 0 ? 1 : 0;
		while (i++ < strt->width - strt->data_len)
			ft_putchar('0', strt);
	}
	else if (strt->data_len < strt->prec)
	{
		i = 0;
		while (i++ < strt->prec - strt->data_len)
			ft_putchar('0', strt);
	}
}
