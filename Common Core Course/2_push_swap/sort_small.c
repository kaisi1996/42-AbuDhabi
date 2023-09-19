/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:16:05 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/13 12:13:29 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_3(t_stack_addresses *a, t_stack_addresses *b, t_extra *v)
{
	if (v->pos_neg_len[2] == 6)
	{
		sort_3_a(a);
		sort_3_b(b);
		write(1, "pa\npa\npa\n", 9);
	}
	else if (v->pos_neg_len[2] == 5)
	{
		sort_3_a(a);
		if (b->first->index > b->last->index)
			write(1, "pa\npa\n", 6);
		else
			write(1, "sb\npa\npa\n", 9);
	}
}

void	sort_small_2(t_stack_addresses *a, t_stack_addresses *b, t_extra *v)
{
	int	pos_neg_l[3];

	pos_neg_len(b->first, pos_neg_l);
	while (pos_neg_l[2] < v->median - 1)
	{
		if (a->first->index < v->median - 1)
		{
			push_to_a(b, a);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		pos_neg_len(b->first, pos_neg_l);
	}
	sort_small_3(a, b, v);
	free_stack(b->first);
}

void	sort_small(t_stack_addresses *a, t_stack_addresses *b, t_extra *v)
{
	if (v->pos_neg_len[2] == 2)
		write(1, "sa\n", 3);
	else if (v->pos_neg_len[2] == 3)
		sort_3_a(a);
	else if (v->pos_neg_len[2] == 4)
	{
		write(1, "pb\n", 3);
		push_to_a(b, a);
		sort_3_a(a);
		if (b->first->index == 0)
			write(1, "pa\n", 3);
		else if (b->first->index == 3)
			write(1, "pa\nra\n", 6);
		else if (b->first->index == 1)
			write(1, "ra\npa\nrra\n", 10);
		else if (b->first->index == 2)
			write(1, "rra\npa\nra\nra\n", 13);
		free_stack(b->first);
	}
	else
		sort_small_2(a, b, v);
}
