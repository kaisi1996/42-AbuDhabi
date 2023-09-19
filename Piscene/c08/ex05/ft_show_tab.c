/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:37:16 by aalkaisi          #+#    #+#             */
/*   Updated: 2022/08/23 16:14:14 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	wr(char c)
{
	write(1, &c, 1);
}

void	wr_num(int nb)
{
	int		exp;
	char	what;

	exp = 1000000000;
	what = 'N';
	while (exp > 0)
	{
		if (nb / exp == 0 && what == 'N')
			exp = exp / 10;
		else
		{
			what = 'Y';
			wr(nb / exp + 48);
			nb = nb - (nb / exp) * exp;
			exp = exp / 10;
		}
	}
	if (nb == 0 && what == 'N')
		write(1, &"0", 1);
}

void	wr_string(char *p)
{
	int	i;

	i = 0;
	while (p[i] != '\0')
	{
		write(1, &p[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		wr_string(par[i].str);
		write(1, &"\n", 1);
		wr_num(par[i].size);
		write(1, &"\n", 1);
		wr_string(par[i].copy);
		write(1, &"\n", 1);
		i++;
	}
}
