/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:08:24 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/03/11 06:53:36 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wr(char c)
{
	write(1, &c, 1);
}

int	loop(int exp, int *n, char *what, int count)
{
	while (exp > 0 && *n != -2147483648)
	{
		if (*n < 0)
		{
			*n = -1 * *n;
			write(1, &"-", 1);
			count++;
		}
		if (*n / exp == 0 && *what == 'N')
			exp = exp / 10;
		else
		{
			*what = 'Y';
			wr(*n / exp + 48);
			count++;
			*n = *n - (*n / exp) * exp;
			exp = exp / 10;
		}
	}
	return (count);
}

int	ft_putnbr(int n, char flag)
{
	int		exp;
	char	what;
	int		count;

	exp = 1000000000;
	what = 'N';
	count = 0;
	if (n >= 0 && (flag == ' ' || flag == '+'))
	{
		write(1, &flag, 1);
		count++;
	}
	if (n == -2147483648)
	{
		write(1, &"-2147483648", 11);
		count = 11;
	}
	count = loop(exp, &n, &what, count);
	if (n == 0 && what == 'N')
	{
		write(1, &"0", 1);
		count++;
	}
	return (count);
}
