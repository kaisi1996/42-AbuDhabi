/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:12:38 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/11 11:46:53 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

int	digits_num(int n)
{
	int	number;
	int	num_of_digits;

	num_of_digits = 0;
	number = n;
	if (number < 0 && number != -2147483648)
	{
		number = n * -1;
		num_of_digits++;
	}
	if (number == 0)
		num_of_digits++;
	while (number >= 1)
	{
		number /= 10;
		num_of_digits++;
	}
	if (number == -2147483648)
		num_of_digits = 11;
	return (num_of_digits);
}

void	find_res1(int n, char *res)
{
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		res[2] = '1';
		res[3] = '4';
		res[4] = '7';
		res[5] = '4';
		res[6] = '8';
		res[7] = '3';
		res[8] = '6';
		res[9] = '4';
		res[10] = '8';
	}
	if (n == 0)
		res[0] = '0';
}

void	find_res2(int n, int number, int index, char *res)
{
	int	div;

	if (n < 0 && n != -2147483648)
	{
		res[index++] = '-';
		number = n * -1;
		n = -1 * n;
	}
	div = 1;
	if (n > 0)
	{
		while (number > 9)
		{
			div *= 10;
			number /= 10;
		}
		while (div >= 1)
		{
			res[index++] = n / div + '0';
			n = n - (n / div) * div;
			div /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		num_of_digits;
	int		number;
	int		index;

	num_of_digits = digits_num(n);
	res = malloc(num_of_digits + 1);
	if (res == NULL)
		return (NULL);
	find_res1(n, res);
	number = n;
	index = 0;
	find_res2(n, number, index, res);
	res[num_of_digits] = '\0';
	return (res);
}
