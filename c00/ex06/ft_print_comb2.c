/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:45:36 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/07 21:49:15 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_show(int i, int j)
{
	ft_putchar('0' + (i / 10));
	ft_putchar('0' + (i % 10));
	write(1, " ", 1);
	ft_putchar('0' + (j / 10));
	ft_putchar('0' + (j % 10));
	if (i != 98 || j != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_show(i, j);
			j++;
		}
		i++;
	}
}
