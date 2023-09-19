/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:20:35 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/18 11:47:16 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*a;

	if (max > min)
	{
		a = malloc(sizeof(int) * (max - min));
		if (a == NULL)
			return (-1);
		i = 0;
		while (i < max - min)
		{
			a[i] = min + i;
			i++;
		}
		*range = a;
		return (max - min);
	}
	*range = NULL;
	return (0);
}
