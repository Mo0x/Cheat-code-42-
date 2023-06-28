/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:39:57 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/19 11:48:01 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{	
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] > 8 && base[i] < 14) \
		|| base[i] == ' ')
			return (0);
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base [i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_base_to_dec(char c, char *base)
{
	int	i;

	i = 0;
	while (c != base[i] && base[i])
		i++;
	if (i >= ft_strlen(base))
		return (-2);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	is_neg;
	int	ret;

	i = 0;
	ret = 0;
	is_neg = 1;
	if (!ft_check_base(base))
		return (0);
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_neg *= -1;
		i++;
	}
	while (str[i] && ft_base_to_dec(str[i], base) > -1)
	{
		ret = (ret * ft_strlen(base)) + ft_base_to_dec(str[i], base);
		i++;
	}
	return (ret * is_neg);
}
