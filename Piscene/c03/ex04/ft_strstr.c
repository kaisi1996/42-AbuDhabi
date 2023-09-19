/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:43:48 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/11 12:22:38 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (to_find[count] != '\0')
		count++;
	i = 0;
	while (str[i] != '\0' && count != 0)
	{
		j = 0;
		while (to_find[j] == str[i + j] && to_find[j] != '\0')
			if (str[i + j] != '\0')
				j++;
		if (count == j)
			return (&str[i]);
		i++;
	}
	if (count == 0)
		return (str);
	else
		return (0);
}
