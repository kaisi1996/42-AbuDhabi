/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 03:52:44 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/03/11 07:42:28 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	conv(long int dec_num)
{
	long int	res;

	if (dec_num >= 0)
		res = dec_num;
	else
		res = 4294967295 + dec_num;
	return (res);
}

int	putdigit(int digit, char c)
{
	int	count;

	if (digit <= 9)
		count = ft_putnbr(digit, 'N');
	else if (c == 'x')
		count = ft_putchar('a' + digit - 10);
	else
		count = ft_putchar('A' + digit - 10);
	return (1);
}

int	putall(int remainder[8], char c, int i)
{
	int		count;
	char	flag;

	count = 0;
	flag = 'N';
	i--;
	while (i >= 0)
	{
		if (remainder[i] != 0 || flag == 'Y')
		{
			count += putdigit(remainder[i], c);
			flag = 'Y';
		}
		i--;
	}
	return (count);
}

int	puthexa_sym(char flag, long int res, char c)
{
	int	count;

	count = 0;
	if (flag == '#' && res != 0)
	{
		if (c == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		count = 2;
	}
	return (count);
}

int	ft_puthexad(long int dec_num, char c, char flag)
{
	int			i;
	long int	res;
	int			remainder[8];
	int			count;

	i = 0;
	res = conv(dec_num);
	count = puthexa_sym(flag, res, c);
	if (res == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (i < 8 && res != 0)
	{
		remainder[i] = res % 16;
		res = res / 16;
		i++;
	}
	count += putall(remainder, c, i);
	return (count);
}
