/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:49:37 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/15 13:12:22 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t n)
{
	const char	*dst;
	const char	*source;
	size_t		len;
	size_t		size;

	dst = (const char*)dest;
	source = (const char*)src;
	len = n;
	while (len-- != 0 && *dest != '\0')
		dest++;
	size = dest - dst;
	len = n - size;
	if (len-- == 0)
		return (size + ft_strlen(src));
	while (*src != '\0')
	{
		if (len != 0)
		{
			*dest++ = *src;
			len--;
		}
		src++;
	}
	*dest = '\0';
	return (size + (src - source));
}
