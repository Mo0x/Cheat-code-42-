/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:16:38 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/17 21:16:56 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_am_i_prime(int nb)
{
	int	ret;
	int	i;

	if (nb == 2)
		return (1);
	if (nb < 2 || nb % 2 == 0)
		return (0);
	i = 3;
	ret = 1;
	while (i <= (nb / i))
		if (nb % i++ == 0)
			ret = 0;
	return (ret);
}

int	ft_find_next_prime(int nb)
{
	if (ft_am_i_prime(nb))
		return (nb);
	while (!ft_am_i_prime(nb))
		nb++;
	return (nb);
}
