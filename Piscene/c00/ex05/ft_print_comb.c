/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:12:36 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/03 21:12:44 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = '0';
	while (num1 <= '7')
	{
		num2 = num1 + 1;
		while (num2 <= '8')
		{
			num3 = num2 + 1;
			while (num3 <= '9')
			{
				write(1, &num1, 1);
				write(1, &num2, 1);
				write(1, &num3, 1);
				if (num1 != '7' || num2 != '8' || num3 != '9')
					write(1, &", ", 2);
				num3++;
			}
			num2++;
		}
		num1++;
	}
}

/*int main()
{
	ft_print_comb();
}*/

/*void	ft_print_comb(void)
{
	int	num;
	int	m;
	int	digit1;
	int	digit2;
	int	digit3;

	num = 12;
	m = 0;
	while (num <= 789)
	{
		digit1 = num / 100 + 48;
		digit2 = (num - 100 * (digit1 - 48)) / 10 + 48;
		digit3 = num - 100 * (digit1 - 48) - 10 * (digit2 - 48) + 48;
		write(1, &digit1, 1);
		write(1, &digit2, 1);
		write(1, &digit3, 1);
		if (!(digit1 - 48 == 7 && digit2 - 48 == 8 && digit3 - 48 == 9))
			write(1, ", ", 2);
		if (digit3 - 48 == 9)
		{
			num = num + 4 + m;
			m++;
		}
		else
			num++;						
	}
}*/
