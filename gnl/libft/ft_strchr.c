/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:29:58 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/15 13:14:01 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s[i] == c)
		return ((char*)&s[i]);
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == c)
			return ((char*)&s[i]);
	}
	return (NULL);
}
