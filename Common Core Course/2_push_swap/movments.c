/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:03:13 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/12 16:12:58 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack_addresses *a, t_stack_addresses *b)
{
	t_stack	*c;

	if (b->first == NULL)
		return ;
	c = b->first;
	b->first = b->first->next;
	if (b->first != NULL)
		b->first->back = NULL;
	c->next = a->first;
	if (a->first != NULL)
		a->first->back = c;
	else
		a->last = c;
	a->first = c;
}

void	rotate(t_stack_addresses *a)
{
	t_stack	*b;

	if (a->first == NULL || a->first == a->last)
		return ;
	b = a->first;
	a->first = a->first->next;
	a->first->back = NULL;
	b->back = a->last;
	a->last->next = b;
	b->next = NULL;
	a->last = b;
}

void	rev_rotate(t_stack_addresses *a)
{
	t_stack	*b;

	if (a->first == NULL || a->first == a->last)
		return ;
	b = a->last;
	a->last = a->last->back;
	a->last->next = NULL;
	b->next = a->first;
	a->first->back = b;
	b->back = NULL;
	a->first = b;
}

void	swap(t_stack *a)
{
	t_stack	*b;
	int		c;
	int		index;

	if (a == NULL || a->next == NULL)
		return ;
	b = a->next;
	c = b->num;
	b->num = a->num;
	a->num = c;
	index = a->index;
	a->index = b->index;
	b->index = index;
}
