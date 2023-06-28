/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:37:40 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/27 12:48:14 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		n = -nb;
		write(1, "-", 1);
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

int	arg_sorter(int ac, char **av)
{
	if (ac != 4)
		return (-1);
	if (ft_strcmp(av[2], "+") == 0)
		return (0);
	else if (ft_strcmp(av[2], "-") == 0)
		return (1);
	else if (ft_strcmp(av[2], "*") == 0)
		return (2);
	else if (ft_strcmp(av[2], "/") == 0)
		return (3);
	else if (ft_strcmp(av[2], "%") == 0)
		return (4);
	else
	{
		write(1, "0\n", 2);
		return (-1);
	}
}

int	main(int ac, char **av)
{
	int	flags;
	int	(*function_arr[5])(int, int);
	int	ret;

	ret = 0;
	flags = arg_sorter(ac, av);
	if (flags < 0)
		return (0);
	if (ft_check_zero(ft_atoi(av[3]), flags))
		return (0);
	function_arr[0] = ft_add;
	function_arr[1] = ft_sub;
	function_arr[2] = ft_mul;
	function_arr[3] = ft_div;
	function_arr[4] = ft_mod;
	ret = function_arr[flags](ft_atoi(av[1]), ft_atoi(av[3]));
	ft_putnbr(ret);
	write(1, "\n", 1);
	return (0);
}
