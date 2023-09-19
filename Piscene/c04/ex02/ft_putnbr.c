/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:01:38 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/14 18:50:36 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wr(char c)
{
	write(1, &c, 1);
}

void	loop(int *exp, int *nb, char *what)
{
	while (*exp > 0 && *nb != -2147483648)
	{
		if (*nb < 0)
		{
			*nb = -1 * *nb;
			write(1, &"-", 1);
		}
		if (*nb / *exp == 0 && *what == 'N')
			*exp = *exp / 10;
		else
		{
			*what = 'Y';
			wr(*nb / *exp + 48);
			*nb = *nb - (*nb / *exp) * *exp;
			*exp = *exp / 10;
		}
	}
}

void	ft_putnbr(int nb)
{
	int		exp;
	char	what;

	exp = 1000000000;
	what = 'N';
	if (nb == -2147483648)
		write(1, &"-2147483648", 11);
	loop(&exp, &nb, &what);
	if (nb == 0 && what == 'N')
		write(1, &"0", 1);
}
