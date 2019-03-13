/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 08:14:42 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/16 07:56:19 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (int)n;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && j < k)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
