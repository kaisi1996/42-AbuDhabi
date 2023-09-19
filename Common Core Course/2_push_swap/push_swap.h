/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:52:22 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/08/13 11:24:54 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <stdint.h>

typedef struct stack
{
	int				num;
	int				index;
	struct stack	*next;
	struct stack	*back;
}	t_stack;

typedef struct stack_addresses
{
	t_stack	*first;
	t_stack	*last;
}	t_stack_addresses;

typedef struct extra
{
	int		pos_neg_len[3];
	int		median;
}	t_extra;

int		find_error(char **str_list);
int		duplicate_check(char **str_list);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strtrim(char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
int		ft_atoi_check(char **str_list);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	pos_neg_len(t_stack *a, int pos_neg_len[]);
void	find_index(t_stack_addresses *a, int len);
void	push_to_a(t_stack_addresses *a, t_stack_addresses *b);
void	rotate(t_stack_addresses *a);
void	rev_rotate(t_stack_addresses *a);
void	swap(t_stack *a);
void	sort_3_b(t_stack_addresses *a);
void	sort_3_a(t_stack_addresses *a);
void	sort_large(t_stack_addresses *a, 
			t_stack_addresses *b, t_extra *v_for_a);
void	sort_small(t_stack_addresses *a, t_stack_addresses *b, t_extra *v);
void	free_list_str(char **str_list);
void	free_stack(t_stack *a);
t_stack	*put_all_in_a(char **str_list, t_stack_addresses *stack_a);
void	set_b(t_stack_addresses *b);
int		find_error_sp(int argc, char **argv);

#endif