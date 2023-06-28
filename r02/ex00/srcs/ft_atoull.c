/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:05:00 by wkeiser           #+#    #+#             */
/*   Updated: 2023/06/25 17:14:41 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_isspace(char c)
{
	if ((c >= 9) && (c <= 13 || c == 32))
		return (1);
	return (0);
}

int	ft_is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

unsigned long long	ft_verif_ret(unsigned long long nb)
{
	if ((nb > 18446744073709551615U) || nb < (0))
		return (-1);
	else if (nb == 0)
		return (0);
	else
		return (nb);
}

unsigned long long	ft_atoull(char *str)
{
	int					i;
	unsigned long long	rep;

	i = 0;
	rep = 0;
	while (ft_isspace(str[i]))
		i++;
	while (ft_is_numeric(str[i]) && str[i])
	{
		rep *= 10;
		rep += str[i++] - 48;
	}
	rep = ft_verif_ret(rep);
	return (rep);
}
