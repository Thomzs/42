/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:36:41 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/05 23:58:54 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		check_path(char *path)
{
	int i;
	
	i = ft_strlen(path);
	if (path[i - 2] == '/' && path[i - 1] == '.' && path[i] == '\0')
		return (0);
	if (path[i - 3] == '/' && path[i - 2] == '.' 
			&& path[i - 1] == '.' && path[i] == '\0')
		return (0);
	return (1);
}

void			recursive(t_list **arg, char flag)
{
	t_list *start;

	start = *arg;
	while (start)
	{
		if ((start->buf.st_mode & S_IFMT) == S_IFDIR && check_path(start->path))
		{	
			ft_printf("\n%s:\n", start->path);
			ft_ls(start->path, flag);
		}
		start = start->next;
	}
}

void			rev_list(t_list **arg)
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

void			swap(t_list *a, t_list *b)
{
	t_list temp;
	
	temp.buf = a->buf;
	temp.pw = a->pw;
	temp.gr = a->gr;
	temp.name = a->name;
	temp.path = a->path;
	a->buf = b->buf;
	a->pw = b->pw;
	a->gr = b->gr;
	a->name = b->name;
	a->path = b->path;
	b->buf = temp.buf;
	b->pw = temp.pw;
	b->gr = temp.gr;
	b->name = temp.name;
	b->path = temp.path;
}

void			sort_list(t_list **head)
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
