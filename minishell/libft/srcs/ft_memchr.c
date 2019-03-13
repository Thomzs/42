/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:55:52 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/15 13:16:24 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*str;

	i = 0;
	uc = (unsigned char)c;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == uc)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
