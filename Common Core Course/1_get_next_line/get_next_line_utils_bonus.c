/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:48 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/07/11 16:52:53 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*var;
	size_t	i;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	var = malloc(count * size);
	if (var == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)var)[i] = 0;
		i++;
	}
	return (var);
}

char	*ft_strjoin2(char const *s1, char const *s2, char *res)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	free((void *)s1);
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = s2[j];
	if (s2[j] == '\n')
		res[i + j + 1] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && s2[j] != '\n')
		j++;
	if (s2[j] == '\n')
		res = malloc(i + j + 2);
	else
		res = malloc(i + j + 1);
	if (res == NULL)
		return (NULL);
	res = ft_strjoin2(s1, s2, res);
	return (res);
}

int	index_strlen(char *str, char c, char *s, char d)
{
	int	i;
	int	len;

	if (d == 'i')
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == c)
				return (i);
			i++;
		}
		return (-1);
	}
	else
	{
		len = 0;
		while (s[len] != '\0')
			len++;
		return (len);
	}
}

void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}
