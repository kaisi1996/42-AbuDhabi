/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:01:33 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/11 11:57:54 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	p = NULL;
	if (s == NULL)
		return (NULL);
	i = (unsigned int)ft_strlen(s);
	if (start >= i)
		return (ft_strdup(""));
	if (i - start <= len)
		p = (char *)malloc(i - start + 1);
	else
		p = (char *)malloc(len + 1);
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
