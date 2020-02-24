/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:43:32 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/24 17:06:44 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*i;

	i = malloc(size);
	if (i == NULL)
		return (NULL);
	ft_memset(i, 0, size);
	return (i);
}
