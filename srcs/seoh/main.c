/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 02:07:51 by seoh              #+#    #+#             */
/*   Updated: 2020/09/25 03:48:45 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int tmp;
	int tmp2;

	int a = printf("pf:\t218+1:\t%16.12d\t\tf:%15.12i\n",-42, 42);
	fflush(stdout);
	int a_f = ft_printf("ft:\t218+1:\t%16.12d\t\tf:%15.12i\n",-42, 42);
	fflush(stdout);
    int b = printf("pf:\t218:\t%12.12d\tf:%12.12i\n",-42, 42);
	fflush(stdout);
    int b_f = ft_printf("ft:\t218:\t%12.12d\tf:%12.12i\n",-42, 42);
	fflush(stdout);
    int c = printf("pf:\t218-1:\t%11.12d\tf:%11.12i\n",-42, 42);	
	fflush(stdout);
    int c_f = ft_printf("ft:\t218-1:\t%11.12d\tf:%11.12i\n",-42, 42);
	fflush(stdout);

	printf("pf :\t%d\t%d\t%d\nft :\t%d\t%d\t%d\t\n",a,b,c,a_f,b_f,c_f);	
	fflush(stdout);
	printf("printf return value : %d\nft_printf return value : %d\n", tmp, tmp2);
}