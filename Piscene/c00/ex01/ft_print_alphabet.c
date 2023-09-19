/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:29:14 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/03 17:30:56 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	write(1, &"abcdefghijklmnopqrstuvwxyz", 26);
}

/*void ft_print_alphabet(void)
{
	char a = 'a';

	while(a <= 'z')
	{
		write(1,&a,1);
		a++;
	}

}*/

/*int main()
{
    ft_print_alphabet();
} */
