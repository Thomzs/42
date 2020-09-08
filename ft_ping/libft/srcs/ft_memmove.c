/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 08:59:40 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/15 13:15:50 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*source;
	char	*dest;

	source = (char*)src;
	dest = (char*)dst;
	i = (src < dst ? len - 1 : 0);
	if (src < dst && len != 0)
	{
		while (i > 0)
		{
			dest[i] = source[i];
			i--;
		}
		dest[i] = source[i];
	}
	if (src > dst && len != 0)
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dest);
}
