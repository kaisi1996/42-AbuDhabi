/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:21:11 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/09/06 17:38:52 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_of_num(int i)
{
	int	big;
	int	digit;
	int	count;

	count = 0;
	if (i < 0)
	{
		i = -i;
		count++;
	}
	else if (i == 0)
		return (1);
	big = 1000000000;
	while (i / big == 0)
		big = big / 10;
	while (big > 0)
	{
		digit = i / big;
		i = i - big * digit;
		big = big / 10;
		count++;
	}
	return (count);
}

void	ft_itoa_block2(char *res, int nbr)
{
	int	i;
	int	big;
	int	digit;

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		res[i] = '-';
		i++;
	}
	big = 1000000000;
	while (nbr / big == 0)
	{
		big = big / 10;
	}
	while (big > 0)
	{
		digit = nbr / big;
		nbr = nbr - big * digit;
		big = big / 10;
		res[i] = digit + '0';
		i++;
	}
	res[i] = '\0';
}

char	*ft_itoa(int nbr)
{
	char	*res;
	int		size_;

	if (nbr == 0)
	{
		res = malloc(1 + 1);
		res = "0";
		return (res);
	}
	else if (nbr == -2147483648)
	{
		res = malloc(11 + 1);
		res = "-2147483648";
		return (res);
	}
	size_ = size_of_num(nbr);
	res = malloc(size_ + 1);
	ft_itoa_block2(res, nbr);
	return (res);
}
