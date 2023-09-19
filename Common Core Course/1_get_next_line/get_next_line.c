/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:03:43 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/07/11 19:51:33 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	index_(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*swap_self_mem(char *extra_str)
{
	char	*temp;

	if (index_(extra_str, '\n') != -1)
	{
		temp = ft_calloc(ft_strlen(extra_str) - index_(extra_str, '\n'), 1);
		ft_strcpy(temp, extra_str + index_(extra_str, '\n') + 1);
		free((void *)extra_str);
		extra_str = temp;
	}
	else
	{
		free((void *)extra_str);
		extra_str = ft_calloc(1, 1);
		extra_str[0] = '\0';
	}
	return (extra_str);
}

char	*put_buffer(char *res, char buf[], char *extra_str, int fd)
{
	int	j;

	while (index_(buf, '\n') == -1 && index_(res, '\n') == -1 && 
		extra_str[0] == '\0')
	{
		j = read(fd, buf, BUFFER_SIZE);
		if (j == 0 && res[0] != '\0')
		{
			buf[0] = '\0';
			return (res);
		}
		else if (j <= 0)
		{
			free((void *)res);
			res = NULL;
			return (NULL);
		}
		buf[j] = '\0';
		res = ft_strjoin(res, buf);
	}
	return (res);
}

char	*free_block(char buf[], char *extra_str)
{
	if (buf[0] != '\0')
	{
		free((void *)extra_str);
		extra_str = ft_calloc(ft_strlen(buf) - index_(buf, '\n'), 1);
		ft_strcpy(extra_str, buf + index_(buf, '\n') + 1);
	}
	if (extra_str[0] == '\0')
	{
		free((void *)extra_str);
		extra_str = NULL;
	}
	return (extra_str);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*extra_str;
	char		*res;

	if (fd < 0)
		return (NULL);
	res = ft_calloc(1, 1);
	res[0] = '\0';
	buf[0] = 0;
	if (extra_str == NULL)
	{
		extra_str = ft_calloc(1, 1);
		extra_str[0] = '\0';
	}
	while (extra_str[0] != '\0' && index_(res, '\n') == -1)
	{
		res = ft_strjoin(res, extra_str);
		extra_str = swap_self_mem(extra_str);
	}
	buf[0] = '\0';
	res = put_buffer(res, buf, extra_str, fd);
	extra_str = free_block(buf, extra_str);
	return (res);
}

int main()
{
	int	fd;
	char *ch;
	
	ch = NULL;
	fd = open("example.txt", O_RDONLY);
	for (int i = 0; i < 12; i++)
	{
		ch = get_next_line(fd);
		printf("result%d: %s,\n", i + 1, ch);
		if (ch != NULL)
		{
			free(ch);
			ch = NULL;
		}
	}
	//ch = get_next_line(-1);
	close(fd);
}
