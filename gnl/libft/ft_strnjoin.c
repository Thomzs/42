/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:08:14 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/28 17:06:00 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	size_t	k;
	char	*str;

	k = ft_strlen(s2);
	k = (len > k ? len : k);
	if ((!s1) || (!s2))
		return (NULL);
	if (!(str = (char*)ft_memalloc(ft_strlen(s1) + k + 1)))
		return (NULL);
	str = ft_strncat(ft_strcpy(str, s1), s2, len);
	return (str);
}
