/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:06:42 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/07 21:07:13 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a / *b;
	*b = *a % *b;
	*a = c;
}

/*int main()
{
	int a = 10, b = 3, div_char, mod_char;
	ft_ultimate_div_mod(&a, &b);
	
	div_char = a + 48;
	mod_char = b + '0';

	write(1, &div_char, 1);
	write(1, &mod_char, 1);
}*/
