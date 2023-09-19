/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:08:01 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/10 15:35:41 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (lst != NULL && del != NULL)
	{
		while (*lst != NULL)
		{
			next_node = (**lst).next;
			del((**lst).content);
			free(*lst);
			*lst = next_node;
		}
		*lst = NULL;
	}
}
