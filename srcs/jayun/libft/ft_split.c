/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 02:50:25 by jayun             #+#    #+#             */
/*   Updated: 2020/10/05 03:19:55 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_size(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (s[i + 1] == '\0' || s[i + 1] == c)
				count++;
		}
		i++;
	}
	return (count);
}

static char	*play_split(char const *s, char c, int *i)
{
	int		j;
	int		k;
	char	*temp;

	j = *i;
	k = 0;
	while (s[j] != c && s[j] != '\0')
		j++;
	temp = (char *)malloc(sizeof(char) * (j - *i + 1));
	if (temp == 0)
		return (0);
	temp[j - *i] = '\0';
	while (*i < j)
	{
		temp[k] = s[*i];
		k++;
		(*i)++;
	}
	return (temp);
}

static char	**play_split2(char const *s, char c, char **result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result[j] = play_split(s, c, &i);
			if (result[j] == 0)
			{
				while (j > 0)
					free(result[--j]);
				free(result);
				return (0);
			}
			j++;
		}
		else
			i++;
	}
	return (result);
}

char		**ft_split(char const *s, char c)
{
	char	**result;
	int		size;

	result = 0;
	if (s != 0)
	{
		size = get_size(s, c);
		result = (char **)malloc(sizeof(char *) * (size + 1));
		if (result == 0)
			return (0);
		result = play_split2(s, c, result);
		if (result == 0)
			return (0);
		result[size] = 0;
	}
	return (result);
}
