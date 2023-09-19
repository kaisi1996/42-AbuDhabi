/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:28:37 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/07 20:31:08 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*int main()
{
	int num1 = 5, num2 = 7;
	int digit1, digit2;

	digit1 = num1 + 48;
	digit2 = num2 + '0';

	write(1, &digit1, 1);
	write(1, &digit2, 1);

	ft_swap(&num1, &num2);

	digit1 = num1 + 48;
	digit2 = num2 + '0';

	write(1, &digit1, 1);
	write(1, &digit2, 1);

}*/
