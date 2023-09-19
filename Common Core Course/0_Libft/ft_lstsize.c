/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:23:25 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/05 12:29:43 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*test;
	int		i;

	i = 0;
	if (lst == NULL)
		return (i);
	i = 1;
	test = (*lst).next;
	while (test != NULL)
	{
		test = (*test).next;
		i++;
	}
	return (i);
}
