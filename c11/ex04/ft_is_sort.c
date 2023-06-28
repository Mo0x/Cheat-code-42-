/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:17:46 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/27 16:42:51 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_sort;

	is_sort = 1;
	i = 1;
	while (i < length && is_sort)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			is_sort = 0;
		i++;
	}
	i = 1;
	if (is_sort != 1)
	{
		is_sort = 1;
		while (i < length && is_sort)
		{
			if (f(tab[i - 1], tab[i]) < 0)
				is_sort = 0;
			i++;
		}
	}
	return (is_sort);
}
