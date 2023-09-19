/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:50:12 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/11 11:57:36 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	start_index(char const *s1, char const *set)
{
	int	skip;
	int	start;
	int	i;

	start = 0;
	skip = 1;
	while (s1[start] != '\0' && skip == 1)
	{
		i = 0;
		skip = 0;
		while (set[i] != '\0' && skip == 0)
		{
			if (set[i] == s1[start])
			{
				start++;
				skip = 1;
			}
			i++;
		}
	}
	return (start);
}

int	end_index(int end, char const *s1, char const *set)
{
	int	skip;
	int	i;

	skip = 1;
	while (end != -1 && skip == 1)
	{
		i = 0;
		skip = 0;
		while (set[i] != '\0' && skip == 0)
		{
			if (set[i] == s1[end])
			{
				end--;
				skip = 1;
			}
			i++;
		}
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		i;
	int		end;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = start_index(s1, set);
	end = ft_strlen(s1) - 1;
	if (s1[start] == '\0')
		start = 0;
	end = end_index(end, s1, set);
	res = (char *)malloc(end - start + 2);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
