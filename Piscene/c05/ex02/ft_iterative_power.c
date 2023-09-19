/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:42:29 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/15 19:50:39 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	results;
	int	i;

	if (power < 0)
		return (0);
	i = 0;
	results = 1;
	while (i < power)
	{
		results = results * nb;
		i++;
	}
	return (results);
}
