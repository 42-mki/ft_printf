/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 19:40:31 by jayun             #+#    #+#             */
/*   Updated: 2020/10/27 18:08:47 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	global_init(void)
{
	g_total_result = NULL;
	g_total_len = 0;
	g_malloc_error = 0;
}

static int	ft_printf_type(const char *str, int left, int i)
{
	int	n;

	n = 1;
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
		n = type_dui(str, left, i);
	else if (str[i] == 'c' || str[i] == '%')
		n = type_perandc(str, left, i);
	else if (str[i] == 's')
		n = type_s(str, left, i);
	else if (str[i] == 'p')
		n = type_p(str, left, i);
	else if (str[i] == 'x' || str[i] == 'X' || str[i] == 'o')
		n = type_xo(str, left, i);
	else if (str[i] == 'n')
		n = type_n(str, left, i);
	else if (str[i] == 'f')
		n = type_f(str, left, i);
	else if (str[i] == 'e')
		n = type_e(str, left, i);
	else if (str[i] == 'g')
		n = type_g(str, left, i);
	return (n);
}

static int	ft_printf_search_type(const char *str, int left, int *i, int n)
{
	if (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u' ||
			str[*i] == 'c' || str[*i] == '%' || str[*i] == 's' || str[*i] == 'p'
			|| str[*i] == 'x' || str[*i] == 'X' || str[*i] == 'o' || str[*i] ==
			'n' || str[*i] == 'f' || str[*i] == 'e' || str[*i] == 'g')
		n = ft_printf_type(str, left, *i);
	else if (str[*i] == 'h')
		n = type_h(str, left, i);
	else if (str[*i] == 'l')
		n = type_l(str, left, i);
	return (n);
}

static int	ft_printf_return(int n)
{
	if (n == 0)
	{
		if (g_total_result != 0)
		{
			write(1, g_total_result, g_total_len);
			free(g_total_result);
		}
		n = g_total_len;
	}
	else if (n != 0)
	{
		if (g_total_result != 0)
			free(g_total_result);
		n = 0;
	}
	return (n);
}

int			ft_printf(const char *str, ...)
{
	int		i;
	int		left;
	int		n;

	global_init();
	va_start(g_ap, str);
	i = -1;
	n = 0;
	while (str[++i] != '\0')
	{
		if (str[i] != '%')
			add_result2(str[i]);
		else
		{
			left = i;
			n = 1;
			while (str[++i] != '\0' && n == 1)
				n = ft_printf_search_type(str, left, &i, n);
			if (n != 0)
				break ;
			i--;
		}
	}
	va_end(g_ap);
	return (ft_printf_return(n));
}
