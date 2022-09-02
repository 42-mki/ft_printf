/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghlee <ml@junghl.ee>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:11:06 by junghlee          #+#    #+#             */
/*   Updated: 2020/11/18 12:19:46 by junghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptf.h"

/*
** ATOI(3)
**
** NAME
** atoi, atoi_l -- convert ASCII string to integer
**
** SYNOPSIS
** #include <stdlib.h>
**
** int atoi(const char *str);
**
** DESCRIPTION
** The atoi() function converts the initial portion of the string pointed
** to by str to int representation.
**
** It is equivalent to:
**
**     (int)strtol(str, (char **)NULL, 10);
**
** STRTOL(3)
**
** NAME
** strtol -- convert a string value to a long
**
** SYNOPSIS
**
** #include <stdlib.h>
**
** long strtol(const char *restrict str, char **restrict endptr, int base);
**
** DESCRIPTION
** The strtol() function converts the string in str to a long value.
** The conversion is done according to the given base,
** which must be between 2 and 36 inclusive, or be the special value 0.
**
** The string may begin with an arbitrary amount of white space
** (as determined by isspace(3)) followed by a single optional
** `+' or `-' sign.
** If base is zero or 16, the string may then include a ``0x'' prefix,
** and the number will be read in base 16; otherwise, a zero base is taken
** as 10 (decimal) unless the next character is `0', in which case
** it is taken as 8 (octal).
**
** The remainder of the string is converted to a long value in the
** obvious manner, stopping at the first character which is not a valid
** digit in the given base.  (In bases above 10, the letter
** `A' in either upper or lower case represents 10, `B' represents 11,
** and so forth, with `Z' representing 35.)
*/

static int	ft_check_overflow_int(int sign, unsigned int u_num)
{
	if (sign == 1 && u_num > 0x7fffffff)
		return (-1);
	else if (sign == -1 && u_num > 0x80000000)
		return (0);
	return (1);
}

int			ptf_atoi(const char *str, size_t *digit_len)
{
	unsigned char	*u_str;
	int				sign;
	unsigned int	u_num;
	int				res;

	u_str = (unsigned char *)str;
	while (ptf_isspace(*u_str))
		u_str++;
	sign = 1;
	if (*u_str == '-' || *u_str == '+')
	{
		if (*u_str == '-')
			sign *= -1;
		u_str++;
	}
	u_num = 0;
	while (ptf_isdigit(*u_str))
	{
		u_num = (u_num * 10) + (*u_str - '0');
		if ((res = ft_check_overflow_int(sign, u_num)) != 1)
			return (res);
		u_str++;
		(*digit_len)++;
	}
	return (sign * u_num);
}

char		*ptf_ulltoa(t_ptinfo *pt, t_ull n, t_ull base, char *base_set)
{
	t_ull	tmp;
	size_t	res_size;
	size_t	i;
	char	*res;

	tmp = n;
	res_size = 0;
	while (tmp)
	{
		tmp /= base;
		res_size++;
	}
	if (!(res = (char *)malloc(sizeof(char) * (res_size + 1))))
		return (0);
	tmp = n;
	pt->print_size += res_size;
	i = 0;
	while (i < res_size)
	{
		*(res + res_size - 1 - i) = *(base_set + (tmp % base));
		tmp /= base;
		i++;
	}
	*(res + i) = '\0';
	return (res);
}
