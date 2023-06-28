/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:04:21 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/19 14:07:04 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_check_base(char *base);
int	ft_base_to_dec(char c, char *base);
int	ft_atoi_base(char *str, char *base);

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) *(ft_strlen(src) + 1));
	if (!ret)
		return (0);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_zero(char *base_to)
{
	char	*ret;

	ret = malloc(sizeof(char *) * 2);
	if (!ret)
		return (0);
	ret[0] = base_to[0];
	ret[1] = 0;
	return (ret);
}

char	*ft_revert_tab(char *str)
{
	int		i;
	int		length;
	char	tmp;

	length = ft_strlen(str) - 1;
	i = 0;
	while (i < length)
	{
		tmp = str[length];
		str[length] = str[i];
		str[i] = tmp;
		i++;
		length--;
	}
	return (str);
}

char	*ft_itoa(int nb, char *base_to)
{
	char			ret[33];
	int				i;
	int				is_neg;
	unsigned int	nbr;
	char			*ret2;

	i = 0;
	is_neg = 0;
	if (nb < 0)
	{
		is_neg = 1;
		nbr = -nb;
	}
	else
		nbr = nb;
	while (nbr)
	{
		ret[i++] = base_to[nbr % ft_strlen(base_to)];
		nbr /= ft_strlen(base_to);
	}
	if (is_neg)
		ret[i++] = '-';
	ret[i] = 0;
	ret2 = ft_strdup(ft_revert_tab(ret));
	return (ret2);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	char	*ret;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	dec = ft_atoi_base(nbr, base_from);
	if (dec == 0)
	{
		ret = ft_zero(base_to);
		return (ret);
	}
	ret = ft_itoa(dec, base_to);
	if (!ret)
		return (NULL);
	return (ret);
}
