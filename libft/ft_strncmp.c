/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:52:51 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/23 20:16:06 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*i1;
	unsigned char	*i2;

	if (n == 0)
		return (0);
	i1 = (unsigned char *)s1;
	i2 = (unsigned char *)s2;
	while ((*i1 && (*i1 == *i2)) && --n)
	{
		if (*i1 != *i2)
			return (*i1 - *i2);
		i1 += 1;
		i2 += 1;
	}
	return (*i1 - *i2);
}
