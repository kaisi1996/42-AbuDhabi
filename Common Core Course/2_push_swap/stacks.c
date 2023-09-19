/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:57:25 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/13 12:12:24 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*var;
	size_t	i;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	var = malloc(count * size);
	if (var == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)var)[i] = 0;
		i++;
	}
	return (var);
}

void	free_list_str(char **str_list)
{
	int	i;

	i = 0;
	while (str_list[i] != NULL)
	{
		free(str_list[i]);
		i++;
	}
	free(str_list);
}

void	free_stack(t_stack *a)
{
	t_stack	*c;

	c = a;
	while (a != NULL)
	{
		c = c->next;
		free(a);
		a = c;
	}
}

t_stack	*put_all_in_a(char **str_list, t_stack_addresses *stack_a)
{
	int		i;
	t_stack	*new_node;

	i = 0;
	stack_a->last = NULL;
	while (str_list[i] != NULL)
	{
		new_node = malloc(sizeof(t_stack));
		if (new_node == NULL)
		{
			free_stack(stack_a->first);
			return (NULL);
		}
		if (i == 0)
			stack_a->first = new_node;
		new_node->num = ft_atoi(str_list[i]);
		new_node->index = -1;
		new_node->next = NULL;
		if (stack_a->last != NULL)
			stack_a->last->next = new_node;
		new_node->back = stack_a->last;
		stack_a->last = new_node;
		i++;
	}
	return (stack_a->first);
}

void	set_b(t_stack_addresses *b)
{
	b->first = NULL;
	b->last = NULL;
}
