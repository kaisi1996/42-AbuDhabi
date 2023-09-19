/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:12:35 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/12 16:13:28 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack_addresses *a, t_stack_addresses *b, 
		t_extra *v_for_b, int bit)
{
	if ((a->first->index >> bit & 1) == 0)
	{
		push_to_a(b, a);
		write(1, "pb\n", 3);
	}
	else
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	pos_neg_len(b->first, v_for_b->pos_neg_len);
}

void	sort_large(t_stack_addresses *a, t_stack_addresses *b, t_extra *v_for_a)
{
	t_extra	v_for_b;
	int		i;
	int		bit;

	pos_neg_len(a->first, v_for_a->pos_neg_len);
	pos_neg_len(b->first, v_for_b.pos_neg_len);
	bit = 0;
	while (v_for_a->pos_neg_len[0] != v_for_a->pos_neg_len[2] - 1)
	{
		i = 0;
		while (i < v_for_a->pos_neg_len[2])
		{
			move_to_b(a, b, &v_for_b, bit);
			i++;
		}
		i = 0;
		while (i < v_for_b.pos_neg_len[2])
		{
			push_to_a(a, b);
			write(1, "pa\n", 3);
			i++;
		}
		bit++;
		pos_neg_len(a->first, v_for_a->pos_neg_len);
	}
}
