/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:18:51 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/10/02 22:09:18 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char *here_doc, int *i, char *str, int argc)
{
	int		j;

	*i = 0;
	j = 0;
	while (here_doc[j] != '\0' && str[j] != '\0' 
		&& here_doc[j] == str[j])
		j++;
	if (here_doc[j] == '\0' && str[j] == '\0')
	{
		*i = 1;
		if (argc < 6)
			exit(1);
	}
}

int	str_cmp(char *str, char *argv, int c)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && argv[i] != '\0' && str[i] == argv[i])
		i++;
	if (c == 1)
	{
		if (str[i] == '\n' && argv[i] == '\0')
			return (1);
	}
	else if (c == 0)
	{
		if (str[i] == '\0' && argv[i] == '\0')
			return (1);
	}
	return (0);
}
