/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:40:47 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/03/10 16:49:59 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putdigit2(int digit)
{
	int	count;

	if (digit <= 9)
		count = ft_putnbr(digit, 'N');
	else
		count = ft_putchar('a' + digit - 10);
	return (1);
}

int	putall2(int remainder[16], int i)
{
	int		count;
	char	flag;

	count = 0;
	flag = 'N';
	i--;
	while (i >= 0)
	{
		count += putdigit2(remainder[i]);
		i--;
	}
	return (count);
}

int	ft_putaddress(unsigned long num)
{
	int	i;
	int	remainder[16];
	int	count;

	write(1, "0x", 2);
	count = 2;
	i = 0;
	while (i < 16 && num != 0)
	{
		remainder[i] = num % 16;
		num = num / 16;
		i++;
	}
	count += putall2(remainder, i);
	if (count == 2)
	{
		write(1, "0", 1);
		count++;
	}
	return (count);
}
