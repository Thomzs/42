/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:05:14 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/15 16:32:09 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*d;

	i = 0;
	c = (unsigned char*)s1;
	d = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && c[i] == d[i])
		i++;
	return (c[i] - d[i]);
}
