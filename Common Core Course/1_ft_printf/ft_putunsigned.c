/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 03:23:43 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/18 03:45:15 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wr2(char c)
{
	write(1, &c, 1);
}

int	loop2(unsigned int *exp, unsigned int *n, char *what)
{
	int	count;

	count = 0;
	while (*exp > 0)
	{
		if (*n / *exp == 0 && *what == 'N')
			*exp = *exp / 10;
		else
		{
			*what = 'Y';
			wr2(*n / *exp + 48);
			count++;
			*n = *n - (*n / *exp) * *exp;
			*exp = *exp / 10;
		}
	}
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	unsigned int	exp;
	char			what;
	int				count;

	exp = 1000000000;
	what = 'N';
	count = loop2(&exp, &n, &what);
	if (n == 0 && what == 'N')
	{
		write(1, &"0", 1);
		count = 1;
	}
	return (count);
}
