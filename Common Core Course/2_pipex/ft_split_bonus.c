/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:45:25 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/10/02 19:36:14 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_substr_block2(char const *s, unsigned int i, 
	unsigned int start, size_t len)
{
	char	*p;

	if (i - start <= len)
		p = malloc(i - start + 1);
	else
		p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < (unsigned int)len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	p = NULL;
	if (s == NULL)
		return (NULL);
	i = (unsigned int)ft_strlen_p(s);
	if (start >= i)
	{
		p = malloc(1);
		if (p == NULL)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	return (ft_substr_block2(s, i, start, len));
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
	t_split	z;

	z.i = 0;
	num = 0;
	while (s[z.i] != '\0')
	{
		while (s[z.i] == c)
			z.i++;
		if (s[z.i] == '\0')
			break ;
		if (s[z.i] != c && s[z.i] != '\0')
		{
			z.start = z.i;
			while (s[z.i] != c && s[z.i] != '\0')
				z.i++;
			z.end = z.i;
		}
		res[num] = ft_substr(s, z.start, (size_t)(z.end - z.start));
		if (res[num] == NULL)
			return (NULL);
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
	if (res == NULL)
		return (NULL);
	return (res);
}
