/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:29:52 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/07/27 16:42:16 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1] && i == 0)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		else if (tab[i] > tab[i + 1] && i != 0)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i--;
		}
		else
			i++;
	}
}

/*int main()
{
	int tab[] = {10, -20, 70, 40};
	int i = 0;

	ft_sort_int_tab(tab, 4);

	while(i < 4)
	{
		printf("%d ", tab[i]);
		i++;
	}

}*/
