/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:23:12 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/06 17:40:02 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int	i;

	i = 0;
	if (max <= min)
		return (0);
	else
	{
		if (!(tab = (int*)malloc(sizeof(int*) * (max - min))))
			return (0);
		while (min < max)
			tab[i++] = min++;
	}
	return (tab);
}
