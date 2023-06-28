/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:37:27 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/19 11:20:45 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*ret;
	int	i;

	size = 0;
	i = 0;
	if (min >= max)
		return (0);
	size = max - min;
	ret = malloc(size * sizeof(int));
	if (!ret)
		return (0);
	while (i < size)
		ret[i++] = min++;
	return (ret);
}
