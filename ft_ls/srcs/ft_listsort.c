/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <tmeyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:36:41 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/17 23:01:39 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_param		*single_struc(char *path)
{
	t_param		*tmp;

	if (!(tmp = (t_param*)malloc(sizeof(t_param))))
		exit(0);
	tmp->path = ft_strdup(path);
	tmp->type = 'w';
	tmp->given = 0;
	tmp->next = NULL;
	return (tmp);
}

static void	swap_param(t_param *a, t_param *b)
{
	t_param tmp;

	tmp.path = a->path;
	tmp.type = a->type;
	a->path = b->path;
	a->type = b->type;
	b->path = tmp.path;
	b->type = tmp.type;
}

void		ascii_param(t_param **head)
{
	int		counter;
	t_param	*i;
	t_param	*j;

	j = NULL;
	counter = 1;
	while (counter == 1)
	{
		i = *head;
		counter = 0;
		while (i->next != j)
		{
			if (ft_strcmp(i->path, i->next->path) > 0)
			{
				swap_param(i, i->next);
				counter = 1;
			}
			i = i->next;
		}
		j = i;
	}
}

t_param		*param_to_list(char *path, t_param **head)
{
	struct stat	buf;
	char		c;
	t_param		*new;

	if (lstat(path, &buf) == -1)
		illegal_opt_path(path);
	else
	{
		if (!(new = malloc(sizeof(t_param))))
			exit(0);
		new->path = ft_strdup(path);
		if ((buf.st_mode & S_IFMT) == S_IFDIR)
			c = 'd';
		else if ((buf.st_mode & S_IFMT) == S_IFLNK)
			c = 'l';
		else
			c = 'r';
		new->type = c;
		new->given = 1;
		new->next = *head;
		*head = new;
	}
	return (*head);
}

int			recursive(t_list **arg, char flag, t_pos t)
{
	t_list			*st;
	t_param			*p;

	st = *arg;
	p = NULL;
	while (st)
	{
		while (1)
		{
			if ((st->buf.st_mode & S_IFMT) == S_IFDIR && check_path(st->name))
			{
				if (!(flag & F_A) && st->name[0] == '.')
					break ;
				p = single_struc(st->path);
				ft_printf("\n%s:\n", st->path);
				ft_ls(p, flag, t);
				if (p)
					ft_lstdel_param(&p);
			}
			break ;
		}
		st = st->next;
	}
	return (1);
}
