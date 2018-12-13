/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:40:54 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/15 13:25:53 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (s[i] == c)
		return ((char*)&s[i]);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
			return ((char*)&s[i]);
	}
	return (NULL);
}
