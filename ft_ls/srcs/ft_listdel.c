/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <tmeyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:49:48 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/19 10:24:17 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lstpurge(t_list **ap)
{
	char	*name;
	char	*path;
	char	*passwd;
	char	*group;

	path = (*ap)->path;
	name = (*ap)->name;
	passwd = (*ap)->pw;
	group = (*ap)->gr;
	if (ap)
	{
		(path) ? free(path) : 0;
		(name) ? free(name) : 0;
		(passwd) ? free(passwd) : 0;
		(group) ? free(group) : 0;
		free(*ap);
	}
}

t_list		*ft_lstdelone(t_list *target)
{
	t_list *tmp;
	t_list *next;

	tmp = target;
	if (tmp)
	{
		next = target->next;
		ft_lstpurge(&tmp);
		return (next);
	}
	return (NULL);
}

void		ft_lstdel(t_list **alst)
{
	if (*alst != NULL)
	{
		ft_lstdel(&((*alst)->next));
		ft_lstdelone(*alst);
	}
}

void		rev_list(t_list **arg)
{
	t_list *prev;
	t_list *current;
	t_list *next;

	prev = NULL;
	current = *arg;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*arg = prev;
}

void		sort_list(t_list **head)
{
	int		counter;
	t_list	*i;
	t_list	*j;

	j = NULL;
	counter = 1;
	while (counter == 1)
	{
		i = *head;
		counter = 0;
		while (i->next != j)
		{
			if (i->buf.st_mtime < i->next->buf.st_mtime)
			{
				swap(i, i->next);
				counter = 1;
			}
			i = i->next;
		}
		j = i;
	}
}
