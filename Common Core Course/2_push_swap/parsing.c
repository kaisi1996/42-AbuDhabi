/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:53:19 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/13 11:13:13 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_error_sp(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0' && argv[i][j] == ' ')
			j++;
		if (ft_strlen(argv[i]) == j)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	find_error(char **str_list)
{
	int	i;
	int	j;

	i = 0;
	while (str_list[i] != NULL)
	{
		j = 0;
		if (str_list[i][0] == '+' || str_list[i][0] == '-')
			j++;
		while (str_list[i][j] != '\0')
		{
			if (!(str_list[i][j] >= '0' && str_list[i][j] <= '9'))
				return (0);
			j++;
		}
		if (j == 1 && (str_list[i][0] == '+' || str_list[i][0] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	duplicate_check(char **str_list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str_list[i] != NULL)
	{
		j = 0;
		while (str_list[j] != NULL)
		{
			if (i != j && ft_atoi(str_list[i]) == ft_atoi(str_list[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
