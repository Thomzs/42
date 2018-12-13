/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:22:01 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/15 13:09:37 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	if (haystack[0] == '\0' && needle[0] != '\0')
		return (NULL);
	if (needle[0] == '\0' || haystack[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j])
		{
			k++;
			j++;
			if (needle[j] == '\0')
				return ((char*)&haystack[k - j]);
		}
		if (haystack[i] != '\0')
			i++;
	}
	return (NULL);
}
