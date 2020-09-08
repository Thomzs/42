/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coyptab_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 09:05:51 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 09:14:25 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_copytab_char(char **tab)
{
	int		i;
	char	**copy;

	copy = NULL;
	i = 0;
	if (!tab || !tab[i])
		return (NULL);
	while (tab[i])
		i++;
	if (!(copy = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = -1;
	while (tab[++i])
		copy[i] = ft_strdup((const char*)tab[i]);
	copy[i] = NULL;
	return (copy);
}
