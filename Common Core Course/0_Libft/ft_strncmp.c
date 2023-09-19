/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:43:40 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/11 11:56:42 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	diff = 0;
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && diff == 0 && i < n)
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (diff == 0 && i < n && ((s1[i] != '\0' && s2[i] == '\0')
			|| (s1[i] == '\0' && s2[i] != '\0')))
	{
		if (s1[i] == '\0' && s2[i] != '\0')
			diff = -1;
		else if (s1[i] != '\0' && s2[i] == '\0')
			diff = 1;
	}
	return (diff);
}
