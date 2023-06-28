/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:25:34 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/09 12:53:59 by mgovinda         ###   ########.fr       */
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

int	ft_str_is_alpha(char *str)
{
	int	is_alpha;
	int	i;

	is_alpha = 1;
	i = -1;
	if (!ft_strlen(str))
		is_alpha = 1;
	while (str[++i])
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			is_alpha = 0;
	return (is_alpha);
}
