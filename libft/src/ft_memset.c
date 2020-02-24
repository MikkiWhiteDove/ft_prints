/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:31:50 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/24 17:07:12 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len != 0)
	{
		*str = (unsigned char)c;
		if (len != 0)
		{
			str++;
		}
		len--;
	}
	return (b);
}
