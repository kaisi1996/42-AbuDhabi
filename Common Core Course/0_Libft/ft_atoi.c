/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:42:48 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/11 11:43:04 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	numbers(int i, long num, int neg, const char *str)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((num > 922337203685477580 && neg == 1) || (num == 922337203685477580
				&& neg == 1 && (str[i] == '8' || str[i] == '9')))
			return (-1);
		else if ((num > 922337203685477580 && neg == -1)
			|| (num == 922337203685477580 && neg == -1
				&& (str[i] == '8' || str[i] == '9')))
			return (0);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		neg;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	num = numbers(i, num, neg, str);
	return (neg * (int)num);
}
