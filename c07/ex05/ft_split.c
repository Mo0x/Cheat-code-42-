/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:38:50 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/19 13:49:47 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	if (charset[0] == '\0')
		return (0);
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

int	ft_strlen_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (!ft_is_charset(str[i], charset) && str[i])
		i++;
	return (i);
}

int	ft_count_words(char *str, char *charset)
{
	int	ret;
	int	i;

	if (str[0] == '\0')
		return (0);
	i = 0;
	ret = 0;
	while (str[i])
	{
		while (ft_is_charset(str[i], charset))
			i++;
		if (str[i])
		{
			ret++;
			while (str[i] && !ft_is_charset(str[i], charset))
				i++;
		}
	}
	return (ret);
}

char	*ft_get_a_word_malloc(char *str, char *charset)
{
	char	*ret;
	int		i;
	int		length_till_nextw;

	i = 0;
	length_till_nextw = ft_strlen_word(str, charset);
	ret = malloc(sizeof(char) * (length_till_nextw + 1));
	if (!ret)
		return (0);
	if (ft_is_charset(str[i], charset))
		while (ft_is_charset(str[i], charset) && str[i])
			i++;
	while (i < ft_strlen_word(str, charset))
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		wc;
	int		i;

	i = -1;
	wc = ft_count_words(str, charset);
	ret = malloc (sizeof(char *) * (wc + 1));
	if (!ret)
		return (0);
	while (++i < wc)
	{
		if (ft_is_charset(*str, charset))
			while (ft_is_charset(*str, charset))
				str++;
		if (!ft_is_charset(*str, charset))
		{
			ret[i] = ft_get_a_word_malloc(str, charset);
			while (*str && !ft_is_charset(*str, charset))
				str++;
		}
	}
	ret[i] = 0;
	return (ret);
}
