/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:34:04 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/05 12:43:35 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_list;

	if (lst == NULL)
		return (NULL);
	last_list = lst;
	while ((*last_list).next != NULL)
		last_list = (*last_list).next;
	return (last_list);
}
