/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:20:11 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/11 14:45:10 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase(char c)
{
	int	is_lower;

	is_lower = 1;
	if (c < 'A' || c > 'Z')
		is_lower = 0;
	return (is_lower);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_char_is_lowercase(str[i]))
				str[i] += 32;
	return (str);
}
