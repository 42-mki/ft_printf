/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:34:06 by seoh              #+#    #+#             */
/*   Updated: 2020/09/25 04:39:51 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** void	print_struct(t_struct *strt)
** {
** 	printf("input_len : %d\n", strt->input_len);
** 	printf("width : %d\n", strt->width);
** 	printf("len : %d\n", strt->len);
** 	printf("align : %d\n", strt->align);
** 	printf("dot : %d\n", strt->dot);
** 	printf("prec : %d\n", strt->prec);
** 	printf("spec : %d\n", strt->spec);
** 	printf("zero : %d\n", strt->zero);
** 	printf("rtn : %d\n", strt->rtn);
** 	printf("data_len : %d\n", strt->data_len);
** }
*/

void	init_struct(t_struct *strt)
{
	strt->width = 0;
	strt->align = 0;
	strt->dot = 0;
	strt->prec = 0;
	strt->spec = 0;
	strt->zero = 0;
	strt->data_len = 0;
}

void	main_process(va_list ap, const char *input, t_struct *strt)
{
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			parse_flags(&input, strt);
			parse_width(&input, strt, ap);
			parse_precision(&input, strt, ap);
			parse_specifier(&input, strt);
			printer(ap, strt);
			init_struct(strt);
		}
		else
		{
			write(1, &*input, 1);
			strt->rtn++;
			input++;
		}
	}
}

int		ft_printf(const char *input, ...)
{
	va_list		ap;
	t_struct	*strt;
	int			rtn;

	if (!(strt = malloc(sizeof(t_struct))))
		return (0);
	strt->rtn = 0;
	init_struct(strt);
	va_start(ap, input);
	main_process(ap, (char *)input, strt);
	rtn = strt->rtn;
	init_struct(strt);
	free(strt);
	return (rtn);
}
