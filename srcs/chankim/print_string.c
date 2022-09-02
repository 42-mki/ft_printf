/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chankim <chankim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:26:56 by chankim           #+#    #+#             */
/*   Updated: 2021/01/25 21:40:34 by chankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*parse_buf(char *str, int end, int len)
{
	int		i;
	char	*buf;

	if (end > len)
		end = len;
	if (!(buf = (char *)malloc(sizeof(char) * end + 1)))
		return (NULL);
	i = 0;
	while (i < end)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int			put_width_str(char **buf, t_info *info)
{
	char	*width;
	int		i;

	if (info->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	width = (char *)malloc(sizeof(char) * (info->width - ft_strlen(*buf) + 1));
	i = 0;
	while ((size_t)i < info->width - ft_strlen(*buf))
	{
		if (info->zero == 1)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (info->minus == 0)
		*buf = ft_strjoin(width, *buf, 3);
	else
		*buf = ft_strjoin(*buf, width, 3);
	return (info->width);
}

int			print_string(char *str, t_info *info)
{
	int		ret;
	char	*buf;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		info->prec = ft_strlen(str);
	buf = parse_buf(str, info->prec, ft_strlen(str));
	ret = put_width_str(&buf, info);
	ft_putstr(buf);
	free(buf);
	return (ret);
}
