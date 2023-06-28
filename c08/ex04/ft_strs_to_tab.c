/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:35:20 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/19 21:10:34 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ret;

	i = -1;
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ret)
		return (0);
	while (str[++i])
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ret;
	int			i;

	i = -1;
	ret = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ret)
		return (NULL);
	while (++i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = av[i];
		ret[i].copy = ft_strdup(av[i]);
	}
	ret[i].str = NULL;
	ret[i].copy = NULL;
	return (ret);
}
