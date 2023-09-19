/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:43:44 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/16 09:48:54 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 2)
		return (2);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
		{
			i = 2;
			nb = nb + 1;
		}
		if (i == 2)
			i++;
		else
			i = i + 2;
	}
	return (nb);
}
