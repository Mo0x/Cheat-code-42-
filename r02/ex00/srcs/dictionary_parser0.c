/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_parser0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:09:09 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/25 20:49:49 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_file_size(int fd)
{
	int		length;
	int		ret;
	char	buffer[1024];

	ret = 0;
	length = 1;
	while (length > 0)
	{
		length = read(fd, buffer, 1024);
		ret += length;
	}
	close(fd);
	return (ret);
}

int	count_entry(char *parsed_dic)
{
	int	ret;
	int	i;

	if (parsed_dic[0] == '\0')
		return (0);
	i = 0;
	ret = 0;
	while (parsed_dic[i])
	{
		while (parsed_dic[i] != '\n')
			i++;
		if (parsed_dic[i] == '\n')
		{
			ret++;
			i++;
		}
	}
	return (ret);
}

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

t_dict	*dic_filler(int size, char *parsed_dic, t_dict *ret)
{
	int	i;

	i = 0;
	while (i < size && *parsed_dic)
	{
		while (*parsed_dic == '\n')
			parsed_dic++;
		ret[i].entry = ft_strdup_till_nl(parsed_dic);
		ret[i].nb = ft_atoull(parsed_dic);
		while (ft_is_charset(*parsed_dic, "0123456789 :"))
			parsed_dic++;
		ret[i].w_number = ft_strdup_till_nl(parsed_dic);
		while (*parsed_dic != '\n')
			parsed_dic++;
		while (*parsed_dic == '\n')
			parsed_dic++;
		i++;
	}
	ret[i].entry = malloc(sizeof(char));
	ret[i].entry[0] = 0;
	ret[i].w_number = 0;
	return (ret);
}

t_dict	*dictionary_parser(char *path_dic)
{
	char	*parsed_dic;
	int		fd;
	int		length;
	int		entrees;
	t_dict	*ret;

	fd = open(path_dic, O_RDONLY);
	length = ft_file_size(fd);
	parsed_dic = malloc(sizeof(char) * (length + 1));
	if (!parsed_dic)
		return (NULL);
	fd = open(path_dic, O_RDONLY);
	read(fd, parsed_dic, length);
	parsed_dic[length + 1] = 0;
	if (!ft_check_dict(parsed_dic))
		return (NULL);
	entrees = count_entry(parsed_dic);
	ret = malloc(sizeof(t_dict) * (entrees + 1));
	if (!ret)
		return (NULL);
	ret = dic_filler(entrees, parsed_dic, ret);
	free(parsed_dic);
	return (ret);
}
