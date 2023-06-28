/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:26:15 by wkeiser           #+#    #+#             */
/*   Updated: 2023/06/25 17:13:47 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h" 

int	ft_check_number(char *nbr)
{
	int			i;

	i = 0;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	while (nbr[i] > 47 && nbr[i] < 58 && nbr[i])
	{
		i++;
	}
	if (nbr[i] == '\0')
		return (1);
	else
		return (-1);
}

int	args_sorter(int ac, char **av)
{
	if ((ac == 1 || ac > 3) || (ac == 2 && ft_check_number(av[1]) == -1)
		|| (ac == 3 && ft_check_number(av[2]) == -1))
	{
		return (-1);
	}
	if (ac == 3)
	{
		return (2);
	}
	else if (ac == 2)
		return (1);
	return (0);
}
