/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:50:24 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/07/11 20:14:56 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

char	*swap_self_mem(char *extra_str)
{
	char	*temp;

	if (index_strlen(extra_str, '\n', NULL, 'i') != -1)
	{
		temp = ft_calloc(index_strlen(NULL, '\0', extra_str, 'l') - 
				index_strlen(extra_str, '\n', NULL, 'i'), 1);
		ft_strcpy(temp, extra_str + 
			index_strlen(extra_str, '\n', NULL, 'i') + 1);
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

	while (index_strlen(buf, '\n', NULL, 'i') == -1 && index_strlen(
			extra_str, '\n', NULL, 'i') == -1 && extra_str[0] == '\0')
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

char	**free_block(char buf[], char **extra_str, int fd)
{
	int	i;

	if (buf[0] != '\0')
	{
		free((void *)extra_str[fd]);
		extra_str[fd] = ft_calloc(index_strlen(NULL, '\0', buf, 'l') - 
				index_strlen(buf, '\n', NULL, 'i'), 1);
		ft_strcpy(extra_str[fd], buf + 
			index_strlen(buf, '\n', NULL, 'i') + 1);
	}
	if (extra_str[fd][0] == '\0')
	{
		free(extra_str[fd]);
		extra_str[fd] = NULL;
	}
	i = 0;
	while (extra_str[i] == NULL && i < 1023)
		i++;
	if (i == 1023 && extra_str[1023] == NULL)
	{
		free(extra_str);
		extra_str = NULL;
	}
	return (extra_str);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	**extra_str;
	char		*res;

	if (fd < 0)
		return (NULL);
	res = ft_calloc(1, 1);
	res[0] = '\0';
	buf[0] = 0;
	if (extra_str == NULL)
		extra_str = ft_calloc(1024, sizeof(char *));
	if (extra_str[fd] == NULL)
	{
		extra_str[fd] = ft_calloc(1, 1);
		extra_str[fd][0] = '\0';
	}
	while (extra_str[fd][0] != '\0' && index_strlen(res, '\n', NULL, 'i') == -1)
	{
		res = ft_strjoin(res, extra_str[fd]);
		extra_str[fd] = swap_self_mem(extra_str[fd]);
	}
	buf[0] = '\0';
	res = put_buffer(res, buf, extra_str[fd], fd);
	extra_str = free_block(buf, extra_str, fd);
	return (res);
}

int main()
{
	int	fd, fd2;
	char *ch;
	// printf("%d\n", fd);

	ch = NULL;
	fd = 42;
	fd2 = open("example2.txt", O_RDONLY);
	for (int i = 0; i < 4; i++)
	{
		ch = get_next_line(fd);
		printf("result%d: %s,\n", i + 1, ch);
		if (ch != NULL)
		{
			free(ch);
			ch = NULL;
		}
	}

	for (int i = 0; i < 12; i++)
	{
		ch = get_next_line(fd2);
		printf("result: %s,\n", ch);
		if (ch != NULL)
		{
			free(ch);
			ch = NULL;
		}
	}
}