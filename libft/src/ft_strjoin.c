/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:00:00 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/24 17:08:34 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = ft_strnew(l1 + l2 + 1);
	if (str)
	{
		ft_memcpy(str, s1, l1);
		ft_memcpy(str + l1, s2, l2);
		str[l1 + l2] = '\0';
		return (str);
	}
	return (NULL);
}
