/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:02:40 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/23 20:16:20 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*res;

	if (!(res = (char *)ft_memalloc(size + 1)))
		return (0);
	i = 0;
	while (i < size)
		res[i++] = '\0';
	return (res);
}
