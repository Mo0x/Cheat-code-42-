/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_parser1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:17:04 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/25 21:06:20 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_char_is_print(char c)
{
	if (c < 32 || c == 127)
		return (0);
	return (1);
}

int	ft_check_dict(char *str)
{
	while (*str)
	{
		while (*str == '\n')
			str++;
		if (ft_is_charset(*str, "0123456789") == 0)
			return (0);
		while (ft_is_charset(*str, "0123456789"))
			str++;
		while (*str == ' ')
			str++;
		if (*str != ':')
			return (0);
		str++;
		while (*str == ' ')
			str++;
		if (ft_char_is_print(*str) == 0)
			return (0);
		while (ft_char_is_print(*str) && *str != '\n')
			str++;
		if (*str != '\n')
			return (0);
		while (*str == '\n')
			str++;
	}
	return (1);
}

int	ft_strlen_till_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	return (i);
}

char	*ft_strdup_till_nl(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen_till_nl(src) + 1));
	if (!ret)
		return (0);
	while (src[i] && src[i] != '\n')
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
