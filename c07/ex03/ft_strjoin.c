/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:45:47 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/20 17:20:31 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_stradd(char *ret, char *str, char *sep, int *index)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ret[*index] = str[i];
		i++;
		(*index)++;
	}
	i = 0;
	while (sep[i])
	{
		ret[*index] = sep[i];
		i++;
		(*index)++;
	}
	return (ret);
}

char	*ft_str_end(char *ret, char *str, int *index)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ret[*index] = str[i];
		i++;
		(*index)++;
	}
	ret[*index] = '\0';
	return (ret);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		length;
	int		i;
	int		j;
	char	*finish;

	finish = malloc(sizeof(char));
	finish[0] = 0;
	length = 0;
	i = 0;
	j = 0;
	if (size < 1)
	{
		return (finish);
	}
	while (i < size)
		length += ft_strlen(strs[i++]);
	ret = malloc(sizeof(char) * (((ft_strlen(sep) * (size - 1)) + length + 1)));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < size - 1)
		ft_stradd(ret, strs[i], sep, &j);
	ft_str_end(ret, strs[i], &j);
	return (ret);
}
