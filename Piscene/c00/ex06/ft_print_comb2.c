/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:52:36 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/03 21:52:58 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wr(char ch)
{
	write(1, &ch, 1);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 99)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			wr(num1 / 10 + 48);
			wr(num1 % 10 + 48);
			write(1, &" ", 1);
			wr(num2 / 10 + 48);
			wr(num2 % 10 + 48);
			if (num1 != 98 || num2 != 99)
				write(1, &", ", 2);
			num2++;
		}
		num1++;
	}
}
/*int main()
{
	ft_print_comb2();
	return 0;
}*/
