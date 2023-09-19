/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:15:00 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/08 12:23:44 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[size - 1 - i];
		tab[size - 1 - i] = tab[i];
		tab[i] = temp;
		i++;
	}
}

/*int main()
{
	int tab[] = {45, 65, 100, 20, 0};
	int i=0;
	ft_rev_int_tab(tab, 5);
	while(i<5)
	{
		printf("%d ", tab[i]);
		i++;
	}

}*/
