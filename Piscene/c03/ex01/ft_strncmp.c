/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:43:40 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/11 12:02:14 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				diff;
	unsigned int	i;

	diff = 0;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && diff == 0 && i < n)
	{
		diff = s1[i] - s2[i];
		i++;
	}
	return (diff);
}
