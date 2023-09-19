/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:46:37 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/18 11:44:06 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;

	if (max > min)
	{
		i = 0;
		p = (int *)malloc(sizeof(int) * (max - min));
		while (i < max - min)
		{
			p[i] = min + i;
			i++;
		}
		return (p);
	}
	return (NULL);
}
