/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:31:20 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/14 23:14:04 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	ret;
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	ret = 1;
	while (((nb / 2) + 1) > i)
		if (nb % i++ == 0)
			ret = 0;
	return (ret);
}
