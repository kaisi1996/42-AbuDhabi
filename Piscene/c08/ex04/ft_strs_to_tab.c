/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:24:04 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/23 15:53:38 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void	cp(t_stock_str *res, char **av, int i, int j)
{
	j = 0;
	while (av[i][j] != '\0')
	{
		res[i].copy[j] = av[i][j];
		j++;
	}
	res[i].copy[j] = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*res;

	i = 0;
	res = malloc(sizeof(t_stock_str) * (ac + 1));
	if (res == NULL)
		return (NULL);
	while (i < ac)
	{
		res[i].str = av[i];
		j = 0;
		while (av[i][j] != '\0')
			j++;
		res[i].size = j;
		res[i].copy = malloc(sizeof(char) * (j + 1));
		if (res[i].copy == NULL)
			return (NULL);
		cp(res, av, i, j);
		i++;
	}
	res[i].str = 0;
	return (res);
}
