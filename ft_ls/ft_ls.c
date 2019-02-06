/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:15:30 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/06 01:52:50 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *path, char flag)
{
	t_list *arg;
	t_list *tmp;
	struct dirent *dirdir;
	DIR		*d;
	int		i;

	arg = NULL;	
	if (!(d = opendir(path)))
	{
		illegal_opt(path);
		i = ft_strrchr(path, 47);
		(i != 0) ? path[i] = '\0' : 0;
		if (!(d = opendir((i == 0) ? "." : path)))
				return ;
		(i != 0) ? path = path + i + 1 : 0;
		while ((dirdir = readdir(d)) != NULL && (ft_strcmp(dirdir->d_name, path)))
			;
		if (dirdir == NULL)
			return ;
		flag |= F_A;
		path -= i + 1;
		ls_insert_elem(&arg, dirdir, ls_create_fp((i == 0) ? "." : path));
	}
	else
	{
		path = ls_create_fp(path);
		//	ft_printf("path : \"%s\"\n", path);
		while ((dirdir = readdir(d)) != NULL)
			ls_insert_elem(&arg, dirdir, path);
	}
	closedir(d);
	if ((!(flag & F_A)) && arg)
	{
		while (arg && arg->name[0] == '.')
			arg = ft_lstdelone(arg);
	}
	(arg) ? ascii_list(&arg) : 0;
	((flag & F_T) && arg) ? sort_list(&arg) : 0;
	((flag & F_RL) && arg) ? rev_list(&arg) : 0;
	tmp = arg;
	while (tmp)
	{
		ft_printperm(tmp);
		tmp = tmp->next;
	}
	if ((flag & F_RU) && arg)
		recursive(&arg, flag);
	if (arg)
		ft_lstdel(&arg);
}

void	ft_sl(int i, char *av[], char flag)
{
	if (av[i])
	{
		while (av[i])
		{
			ft_ls(av[i], flag);
			i++;
		}
	}
	else
		ft_ls(".", flag);
}
