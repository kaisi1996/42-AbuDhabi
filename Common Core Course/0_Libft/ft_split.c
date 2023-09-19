/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:32:43 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/11 11:52:55 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_of_strs(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			num++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (num);
}

char	**save_results(char const *s, char c, int num, char **res)
{
	int				i[2];
	unsigned int	start;
	unsigned int	end;

	i[0] = 0;
	num = 0;
	while (s[i[0]] != '\0')
	{
		while (s[i[0]] == c)
			i[0]++;
		if (s[i[0]] == '\0')
			break ;
		if (s[i[0]] != c && s[i[0]] != '\0')
		{
			start = i[0];
			while (s[i[0]] != c && s[i[0]] != '\0')
				i[0]++;
			end = i[0];
		}
		res[num] = ft_substr(s, start, (size_t)(end - start));
		num++;
	}
	res[num] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int				num;
	char			**res;

	if (s == NULL)
		return (NULL);
	num = num_of_strs(s, c);
	res = (char **)malloc(sizeof(char *) * (num + 1));
	if (res == NULL)
		return (NULL);
	res = save_results(s, c, num, res);
	return (res);
}
