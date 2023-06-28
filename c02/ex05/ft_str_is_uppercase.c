/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:03:38 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/09 14:04:08 by mgovinda         ###   ########.fr       */
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

int	ft_str_is_uppercase(char *str)
{
	int	is_lower;
	int	i;

	is_lower = 1;
	i = -1;
	if (!ft_strlen(str))
		is_lower = 1;
	while (str[++i])
		if (str[i] < 'A' || str[i] > 'Z')
			is_lower = 0;
	return (is_lower);
}
