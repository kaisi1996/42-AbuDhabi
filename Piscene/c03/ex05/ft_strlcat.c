/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:04:18 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/11 12:36:21 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	c;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	c = 0;
	while (src[c] != '\0')
		c++;
	while (src[j] != '\0' && j < size - 1 - i && size > i)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	if (size > i)
		return (c + i);
	else
		return (size + c);
}
