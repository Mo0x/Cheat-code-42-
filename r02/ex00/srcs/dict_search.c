/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:21:12 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/25 21:58:16 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

unsigned long long	dict_max(t_dict *dict)
{
	unsigned long long	nbr;
	int					i;

	i = 0;
	nbr = 0;
	while (dict[i].w_number)
	{
		if (dict[i].nb > nbr)
			nbr = dict[i].nb;
		i++;
	}
	return (nbr);
}

void	ft_free_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].w_number)
	{
		free(dict[i].entry);
		free(dict[i].w_number);
		i++;
	}
	free(dict);
}

char	*dict_search(unsigned long long nbr, t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].w_number)
	{
		if (dict[i].nb == nbr)
		{
			return (dict[i].w_number);
		}
		i++;
	}
	return (NULL);
}
