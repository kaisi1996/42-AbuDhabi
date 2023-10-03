/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:08:20 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/10/02 19:29:57 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	j;
	size_t	count;

	if (haystack == NULL && len == 0)
		return (NULL);
	count = 0;
	j = 0;
	while (needle[count] != '\0')
		count++;
	i = 0;
	while (haystack[i] != '\0' && count != 0)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] != '\0' && i + j < len)
			if (haystack[i + j] != '\0')
				j++;
		if (count == j)
			return ((char *)&haystack[i]);
		i++;
	}
	if (count == 0)
		return ((char *)haystack);
	else
		return (NULL);
}

char	*ft_strjoin3(char const *s1, char *s2, char *s3)
{
	int		i[3];
	char	*res;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (s1 == NULL || s2 == NULL || s3 == NULL)
		return (NULL);
	i[0] = ft_strlen_p(s1);
	i[1] = ft_strlen_p(s2);
	i[2] = ft_strlen_p(s3);
	res = malloc(i[0] + i[1] + i[2] + 1);
	if (res == NULL)
		return (NULL);
	i[0] = -1;
	i[1] = -1;
	i[2] = -1;
	while (s1[++i[0]] != '\0')
		res[i[0]] = s1[i[0]];
	while (s2[++i[1]] != '\0')
		res[i[0] + i[1]] = s2[i[1]];
	while (s3[++i[2]] != '\0')
		res[i[0] + i[1] + i[2]] = s3[i[2]];
	res[i[0] + i[1] + i[2]] = '\0';
	return (res);
}

size_t	ft_strlen_p(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	dup2_func(t_pipex *z, int i, int argc)
{
	if (i == 0)
	{
		dup2(z->fd_files[0], 0);
		dup2(z->fd_pipe[0][1], 1);
	}
	else if (i == argc - 4 - z->i[1])
	{
		dup2(z->fd_files[1], 1);
		dup2(z->fd_pipe[i - 1][0], 0);
	}
	else
	{
		dup2(z->fd_pipe[i - 1][0], 0);
		dup2(z->fd_pipe[i][1], 1);
	}
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		exit(1);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
