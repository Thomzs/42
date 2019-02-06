/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:45:39 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/05 23:58:55 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ascii_list(t_list **head)
{
	int counter;
	t_list *i;
	t_list *j;

	j = NULL;
	counter = 1;
	while (counter == 1)
	{
		i = *head;
		counter = 0;
		while (i->next != j)
		{
			if (ft_strcmp(i->name, i->next->name) > 0)
			{
				swap(i, i->next);
				counter = 1;
			}
			i = i->next;
		}
		j = i;
	}
}
