/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:01:38 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/04 20:21:07 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wr(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		exp;
	char	what;

	exp = 1000000000;
	what = 'N';
	while (exp > 0)
	{
		if (nb < 0)
		{
			nb = -1 * nb;
			write(1, &"-", 1);
		}
		if (nb / exp == 0 && what == 'N')
			exp = exp / 10;
		else
		{
			what = 'Y';
			wr(nb / exp + 48);
			nb = nb - (nb / exp) * exp;
			exp = exp / 10;
		}
	}
	if (nb == 0 && what == 'N')
		write(1, &"0", 1);
}

//   nb / exp = digit
/*int main()
{
	ft_putnbr(-100);
}*/
