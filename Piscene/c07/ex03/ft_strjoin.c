/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:34:59 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/18 11:49:28 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*block1(int size, char **strs, char *sep, int count)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	count = 0;
	if (size <= 0)
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		count = count + j;
		i++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	res = malloc(sizeof(char) * (count + (size - 1) * i + 1));
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		count;
	char	*res;

	count = 0;
	res = block1(size, strs, sep, count);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			res[count++] = strs[i][j++];
		if (i++ < size - 1)
		{
			j = 0;
			while (sep[j] != '\0')
				res[count++] = sep[j++];
		}
	}
	res[count] = '\0';
	return (res);
}
