/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_with_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:17:17 by aalkaisi          #+#    #+#             */
/*   Updated: 2024/03/19 12:17:36 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

long	numbers_check(int i, long num, int neg, const char *str)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		if ((num > 2147483647 && neg == 1) || (num > 2147483648 && neg == -1))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_check(char **str_list, int argc)
{
	int		i;
	int		j;
	long	num;
	int		neg;

	num = 0;
	j = 0;
	while (j < argc - 1)
	{
		i = 0;
		neg = 1;
		if (str_list[j][i] == '-')
		{
			neg *= -1;
			i++;
		}
		else if (str_list[j][i] == '+')
			i++;
		i = numbers_check(i, num, neg, str_list[j]);
		j++;
		if (i == 0)
			return (i);
	}
	return (1);
}
