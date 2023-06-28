/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:06:55 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/07 11:06:58 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_show(int a, int b, int c)
{
	a += '0';
	write(1, &a, 1);
	b += '0';
	write(1, &b, 1);
	c += '0';
	write(1, &c, 1);
	if (a - '0' != 7 || b - '0' != 8 || c - '0' != 9)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 10)
	{
		j = i + 1;
		while (j < 10)
		{
			k = j + 1;
			while (k < 10)
			{
				ft_show(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
