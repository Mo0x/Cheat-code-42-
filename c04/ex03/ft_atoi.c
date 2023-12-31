/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:21:22 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/12 14:12:59 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	is_neg;
	int	ret;

	ret = 0;
	is_neg = 1;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ret = (ret * 10) - '0' + str[i++];
	return (ret * is_neg);
}
