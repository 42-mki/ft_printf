/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 08:16:32 by seoh              #+#    #+#             */
/*   Updated: 2020/09/25 03:03:08 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_struct *strt)
{
	write(1, &c, 1);
	strt->rtn++;
}

void	ft_putstr(const char *s, t_struct *strt)
{
	int		i;

	if (!s || (strt->spec == 's' && strt->dot == 1 && strt->prec == 0))
		return ;
	i = 0;
	if (strt->spec == 's' && strt->prec)
		while (s[i] && i < strt->prec)
			ft_putchar(s[i++], strt);
	else
		while (s[i])
			ft_putchar(s[i++], strt);
}

void	ft_putnbr_base(long long n, char *base, t_struct *strt)
{
	int		basenum;

	if (n == 0 && strt->dot && !strt->prec)
		return ;
	basenum = ft_strlen_pft(base, strt);
	if (n >= basenum)
		ft_putnbr_base((n / basenum), base, strt);
	ft_putchar(base[n % basenum], strt);
}

int		ft_strlen_pft(const char *str, t_struct *strt)
{
	int		i;

	if (str == NULL || (strt->spec == 's' && strt->dot && !strt->prec))
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_nbrlen_base(long long n, char *base, t_struct *strt)
{
	int		i;
	int		basenum;

	if (n == 0 && strt->dot && !strt->prec)
		return (0);
	basenum = ft_strlen_pft(base, strt);
	i = 1;
	while (n >= basenum)
	{
		n /= basenum;
		i++;
	}
	return (i);
}
