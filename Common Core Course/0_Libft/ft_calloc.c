/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaisi <aalkaisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:13:35 by aalkaisi          #+#    #+#             */
/*   Updated: 2023/02/11 11:44:49 by aalkaisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*var;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	var = malloc(count * size);
	if (var == NULL)
		return (NULL);
	ft_bzero(var, count * size);
	return (var);
}
