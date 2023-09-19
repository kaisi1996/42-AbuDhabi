/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:48:29 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/07 20:49:04 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int main()
{
	int x = 10, y = 3, div, mod, div_char, mod_char;

	ft_div_mod(10, y, &div, &mod);

	div_char = div + 48;
	mod_char = mod + '0';

	write(1, &div_char, 1);
	write(1, &" ", 1);
	write(1, &mod_char, 1);
}*/
