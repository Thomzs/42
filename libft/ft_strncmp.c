/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:13:49 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/16 07:37:58 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if ((unsigned char)s1[i] == '\0' ^ (unsigned char)s2[i] == '\0' && i < n)
		return ((unsigned char)s1[i] == '\0' ? -1 : 1);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		j += (unsigned char)s1[i];
		k += (unsigned char)s2[i];
		i++;
	}
	if ((unsigned char)s1[i] == '\0' ^ (unsigned char)s2[i] == '\0' && i < n)
		return ((unsigned char)s1[i] == '\0' ? -1 : 1);
	return (j - k);
}
