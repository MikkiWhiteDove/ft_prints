/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:24:27 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/23 20:15:54 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	if (s == NULL || f == NULL)
		return (NULL);
	map = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (map == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		map[i] = f(s[i]);
	}
	map[i] = '\0';
	return (map);
}
