/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_pnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:11:25 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/12 20:33:23 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_neg_len(t_stack *a, int pos_neg_len[])
{
	t_stack	*b;
	t_stack	*c;

	b = a;
	pos_neg_len[0] = 0;
	pos_neg_len[1] = 0;
	pos_neg_len[2] = 0;
	if (a == NULL)
		return ;
	while (b != NULL)
	{
		b = b->next;
		pos_neg_len[2]++;
	}
	b = a;
	c = a->next;
	while (c != NULL)
	{
		if (b->num < c->num)
			pos_neg_len[0]++;
		else
			pos_neg_len[1]++;
		b = b->next;
		c = c->next;
	}
}

void	find_index(t_stack_addresses *a, int len)
{
	t_stack	*b;
	t_stack	*min;
	int		i;
	int		min_num;

	i = 0;
	while (i < len)
	{
		b = a->first;
		min_num = 2147483647;
		while (b != NULL)
		{
			if (b->num <= min_num && b->index == -1)
			{
				min_num = b->num;
				min = b;
			}
			b = b->next;
		}
		min->index = i;
		i++;
	}
}
