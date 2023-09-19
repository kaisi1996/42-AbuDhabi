/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:03:59 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/03 18:04:22 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int		i;
	char	ch;

	i = 0;
	while (i <= 9)
	{
		ch = i + '0';
		write(1, &ch, 1);
		i++;
	}
}

/*int main()
{
	ft_print_numbers();

}*/
