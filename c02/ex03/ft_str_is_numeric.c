/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:52:08 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/09 13:06:14 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_str_is_numeric(char *str)
{
	int	is_num;
	int	i;

	is_num = 1;
	i = -1;
	if (!ft_strlen(str))
		is_num = 1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			is_num = 0;
	return (is_num);
}
