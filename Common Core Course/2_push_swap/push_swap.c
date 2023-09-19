/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:50:16 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/13 11:33:35 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	block2(char **str_list)
{
	t_stack_addresses	stack_a;
	t_stack_addresses	stack_b;
	t_extra				v;

	stack_a.first = put_all_in_a(str_list, &stack_a);
	set_b(&stack_b);
	free_list_str(str_list);
	pos_neg_len(stack_a.first, v.pos_neg_len);
	if (v.pos_neg_len[0] == v.pos_neg_len[2] - 1)
	{
		free_stack(stack_a.first);
		return ;
	}
	find_index(&stack_a, v.pos_neg_len[2]);
	v.median = (v.pos_neg_len[2] + 2) / 2;
	if (v.pos_neg_len[2] <= 6)
		sort_small(&stack_a, &stack_b, &v);
	else
		sort_large(&stack_a, &stack_b, &v);
	free_stack(stack_a.first);
}

int	main(int argc, char **argv)
{
	char				*str;
	char				**str_list;

	if (argc == 1)
		return (0);
	if (find_error_sp(argc, argv) == 0)
		return (0);
	str = ft_strjoin(argc, argv, " ");
	str = ft_strtrim(str);
	str_list = ft_split(str, ' ');
	free(str);
	if (find_error(str_list) == 0 || ft_atoi_check(str_list) == 0 
		|| duplicate_check(str_list) == 0)
	{
		free_list_str(str_list);
		write(2, "Error\n", 6);
		return (0);
	}
	block2(str_list);
}
