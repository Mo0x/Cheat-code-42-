/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:15:31 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/11 22:08:50 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_addr(unsigned long addr)
{
	char	*base;
	char	buffer[17];
	int		i;

	i = 0;
	base = "0123456789abcdef";
	while (addr)
	{
		buffer[i] = base[addr % 16];
		addr = addr / 16;
		i++;
	}
	while (i < 16)
		buffer[i++] = '0';
	buffer[16] = 0;
	i--;
	while (i > -1)
	{
		ft_putchar(buffer[i]);
		i--;
	}
	write(1, ": ", 2);
}

void	ft_puthex(unsigned char *addr, int offset)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	while (i < 16 && offset - i)
	{
		ft_putchar(base[addr[i] / 16]);
		ft_putchar(base[addr[i] % 16]);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	ft_putstr(unsigned char *str, int offset)
{
	int	i;

	i = 0;
	while (i < 16 && offset--)
	{
		if (str[i] >= ' ' && str[i] <= '~')
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void	*addr, unsigned int size)
{
	unsigned long	offset;
	unsigned long	dec_addr;

	offset = 0;
	dec_addr = (unsigned long) addr;
	while (offset < size)
	{
		ft_put_addr(dec_addr + offset);
		ft_puthex((unsigned char *)(dec_addr + offset), size - offset);
		ft_putstr((unsigned char *)(dec_addr + offset), size - offset);
		ft_putchar('\n');
		offset += 16;
	}
	return (addr);
}
