/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 00:34:46 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/19 20:45:57 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		launcher_two(DIR *d, char *flag, t_param *p, t_list **arg)
{
	struct dirent	*dir;
	char			*str;

	str = NULL;
	if ((*flag & F_L) && (p->type == 'l')
			&& p->path[ft_strl(p->path) - 1] != '/')
	{
		(*flag & F_RU) ? *flag -= F_RU : 0;
		closedir(d);
		special(p->path, arg);
	}
	else
	{
		str = ls_create_fp(p->path);
		while ((dir = readdir(d)) != NULL)
		{
			if (!(*flag & F_A) && dir->d_name[0] == '.')
				continue ;
			ls_insert_elem(arg, dir, str);
		}
		closedir(d);
	}
	if (str)
		free(str);
}

static void	launcher_three(t_pos t, t_param *l2, char flag)
{
	while (l2)
	{
		t.y = 0;
		(l2 && l2->type == 'd') ? ft_ls(l2, flag, t) : 0;
		l2 = l2->next;
		while (l2 && l2->type != 'd')
			l2 = l2->next;
		(l2 && l2->type == 'd') ? ft_printf("\n") : 0;
	}
}

void		launcher_one(t_pos t, t_param *l1, char flag)
{
	t_param	*l2;
	int		i;

	i = 0;
	l2 = l1;
	while (l1)
	{
		while (l1 && l1->type == 'd')
			l1 = l1->next;
		if (!l1)
			break ;
		ft_ls(l1, flag, t);
		i++;
		l1 = l1->next;
	}
	while (l2 && l2->type != 'd')
		l2 = l2->next;
	(l2 && i > 0) ? ft_printf("\n") : 0;
	launcher_three(t, l2, flag);
}

void		ascii_list(t_list **head)
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
