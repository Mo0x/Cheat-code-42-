/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:41:43 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/14 13:48:29 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;
	unsigned int	dest_length;
	unsigned int	j;

	i = 0;
	j = ft_strlen(dest);
	dest_length = ft_strlen(dest);
	length = ft_strlen(dest) + ft_strlen(src);
	if (size == 0 || size <= dest_length)
		return (ft_strlen(src) + size);
	while (i < size - dest_length - 1 && src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = 0;
	return (length);
}
