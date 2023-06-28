/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:13:26 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/07 17:41:41 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_init_tabs(char *tab, char *tab_max, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		tab[i] = i + '0';
		tab_max[i] = (10 - n) + i + '0';
		i++;
	}
}

void	ft_print_tab(char *tab, int size, int last)
{
	int	i;

	i = 0;
	if (tab[0] == last)
	{
		while (i < size)
			ft_putchar(tab[i++]);
		return ;
	}
	while (i < size)
		ft_putchar(tab[i++]);
	write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	char	tab[10];
	char	tab_max[10];
	int		flag;
	int		base;

	if (n < 1 || n > 10)
		return ;
	ft_init_tabs(tab, tab_max, n);
	ft_print_tab(tab, n, tab_max[0]);
	while (tab[0] != tab_max[0])
	{
		flag = n - 1;
		while (tab[flag] == tab_max[flag])
			--flag;
		base = ++(tab[flag]);
		while (flag < n - 1)
			tab[++flag] = ++base;
		ft_print_tab(tab, n, tab_max[0]);
	}
}
