/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:14:41 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/12 16:13:20 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_2_b(t_stack_addresses *a)
{
	if (a->first->index > a->first->next->index && 
		a->first->index > a->last->index && 
		a->first->next->index < a->last->index)
	{
		swap(a->first);
		rotate(a);
		write(1, "sb\nrb\n", 6);
	}
	else if (a->first->index < a->first->next->index && 
		a->first->index < a->last->index && 
		a->first->next->index > a->last->index)
	{
		rotate(a);
		write(1, "rb\n", 3);
	}
	else if (a->first->index < a->first->next->index && 
		a->first->index > a->last->index && 
		a->first->next->index > a->last->index)
	{
		swap(a->first);
		write(1, "sb\n", 3);
	}
}

void	sort_3_b(t_stack_addresses *a)
{
	if (a->first->index > a->first->next->index && 
		a->first->index < a->last->index && 
		a->first->next->index < a->last->index)
	{
		rev_rotate(a);
		write(1, "rrb\n", 4);
	}
	else if (a->first->index < a->first->next->index && 
		a->first->index < a->last->index && 
		a->first->next->index < a->last->index)
	{
		rotate(a);
		rotate(a);
		write(1, "rb\nrb\n", 6);
	}
	else 
		sort_3_2_b(a);
}

void	sort_3_2_a(t_stack_addresses *a)
{
	if (a->first->index > a->first->next->index && 
		a->first->index > a->last->index && 
		a->first->next->index < a->last->index)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (a->first->index < a->first->next->index && 
		a->first->index < a->last->index && 
		a->first->next->index > a->last->index)
	{
		swap(a->first);
		rotate(a);
		write(1, "sa\nra\n", 6);
	}
	else if (a->first->index < a->first->next->index && 
		a->first->index > a->last->index && 
		a->first->next->index > a->last->index)
	{
		rev_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	sort_3_a(t_stack_addresses *a)
{
	if (a->first->index > a->first->next->index && 
		a->first->index < a->last->index && 
		a->first->next->index < a->last->index)
	{
		swap(a->first);
		write(1, "sa\n", 3);
	}
	else if (a->first->index > a->first->next->index && 
		a->first->index > a->last->index && 
		a->first->next->index > a->last->index)
	{
		swap(a->first);
		rev_rotate(a);
		write(1, "sa\nrra\n", 7);
	}
	else 
		sort_3_2_a(a);
}
