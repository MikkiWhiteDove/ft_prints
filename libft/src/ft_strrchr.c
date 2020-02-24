/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:59:40 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/24 17:09:20 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = (int)ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)&s[len + 1]);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)&s[len]);
		len--;
	}
	return (0);
}
