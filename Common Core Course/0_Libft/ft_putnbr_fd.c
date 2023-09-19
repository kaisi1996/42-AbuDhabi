/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:08:24 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/11 11:52:15 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wr(char c, int fd)
{
	write(fd, &c, 1);
}

void	loop(int *exp, int *n, char *what, int fd)
{
	while (*exp > 0 && *n != -2147483648)
	{
		if (*n < 0)
		{
			*n = -1 * *n;
			write(fd, &"-", 1);
		}
		if (*n / *exp == 0 && *what == 'N')
			*exp = *exp / 10;
		else
		{
			*what = 'Y';
			wr(*n / *exp + 48, fd);
			*n = *n - (*n / *exp) * *exp;
			*exp = *exp / 10;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		exp;
	char	what;

	exp = 1000000000;
	what = 'N';
	if (n == -2147483648)
		write(fd, &"-2147483648", 11);
	loop(&exp, &n, &what, fd);
	if (n == 0 && what == 'N')
		write(fd, &"0", 1);
}
