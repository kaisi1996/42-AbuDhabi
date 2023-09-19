/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:45:32 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/13 12:12:40 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*block1(int size, char **strs, char *sep, int count)
{
	int		i;
	int		j;
	char	*res;

	i = 1;
	count = 0;
	if (size <= 1)
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
	res = malloc(sizeof(char) * (count + (size - 1 - 1) * i + 1));
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
	i = 1;
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

int	size_after_trim(char *str)
{
	int		i;
	int		size;
	char	flag;

	i = 0;
	size = 0;
	flag = 'N';
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0' && flag == 'Y')
			size++;
		while (str[i] != ' ' && str[i] != '\0')
		{
			i++;
			size++;
			flag = 'Y';
		}
	}
	return (size);
}

void	ft_strtrim2(char *res, char *str, int size)
{
	int		i;
	char	flag;

	i = 0;
	flag = 'N';
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0' && flag == 'Y')
		{
			res[size] = ' ';
			size++;
		}
		while (str[i] != ' ' && str[i] != '\0')
		{
			res[size] = str[i];
			size++;
			i++;
			flag = 'Y';
		}
	}
	free(str);
	res[size] = '\0';
}

char	*ft_strtrim(char *str)
{
	int		size;
	char	*res;

	if (str == NULL)
		return (NULL);
	size = size_after_trim(str);
	res = (char *)malloc(size + 1);
	if (res == NULL)
		return (NULL);
	size = 0;
	ft_strtrim2(res, str, size);
	return (res);
}
