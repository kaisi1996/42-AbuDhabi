/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:49:08 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/12 16:12:41 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	p = NULL;
	if (s == NULL)
		return (NULL);
	i = (unsigned int)ft_strlen(s);
	if (start >= i)
	{
		p = ft_calloc(1, 1);
		p[0] = '\0';
		return (p);
	}
	if (i - start <= len)
		p = (char *)ft_calloc(i - start + 1, 1);
	else
		p = (char *)ft_calloc(len + 1, 1);
	i = 0;
	while (s[start + i] != '\0' && i < (unsigned int)len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

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
	int				i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		if (s[i] != c && s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			end = i;
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
