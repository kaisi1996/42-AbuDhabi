/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:55:35 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/11 11:57:06 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
