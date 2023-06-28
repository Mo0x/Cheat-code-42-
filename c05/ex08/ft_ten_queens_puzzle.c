/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:58:50 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/17 17:42:13 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_solution(char *tab)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, &tab[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_is_safe(char *tab, int index, int to_test)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (tab[i] == to_test + '0')
			return (0);
		i++;
	}
	i = 0;
	while (i < index)
	{
		if ((tab[i] - index + i == to_test + '0')
			|| (tab[i] + index - i == to_test + '0'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve_backtrack(char *tab, int *count, int col)
{
	if (col == 10)
	{
		ft_print_solution(tab);
		*count = *count + 1;
		return (1);
	}
	tab[col] = '0';
	while (tab[col] - '0' < 10)
	{
		if (ft_is_safe(tab, col, tab[col] - '0'))
			ft_solve_backtrack(tab, &(*count), col + 1);
		tab[col]++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	char	table[10];
	int		count;

	count = 0;
	ft_solve_backtrack(table, &count, 0);
	return (count);
}
