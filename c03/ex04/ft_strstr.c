/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:35:57 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/14 11:25:33 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*ret;
	int		i;

	i = 0;
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			ret = str;
			i = 0;
			while (*(str + i) == *(to_find + i) && *(to_find + i))
			{
				i++;
			}
			if (!*(to_find + i))
				return (ret);
		}
		str++;
	}
	return (0);
}
