/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <tmeyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:15:30 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/19 23:32:44 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		*error_msg(char *str)
{
	char *tmp;

	tmp = ft_strjoin("ft_ls: ", str);
	perror(tmp);
	free(tmp);
	return (NULL);
}

void			special(char *path, t_list **arg)
{
	int				i;
	DIR				*d;
	struct dirent	*dir;
	char			*tmp;

	tmp = ft_strdup(path);
	i = ft_strrchr(path, 47);
	if (i > 0)
		path[i] = '\0';
	d = opendir((i == 0 ? "/" : path));
	(i >= 0) ? path = path + i + 1 : 0;
	while ((dir = readdir(d)) != NULL
			&& (ft_strcmp(dir->d_name, path)))
		;
	path = (i >= 0 ? path - i - 1 : path);
	free(tmp);
	tmp = ls_create_fp(path);
	path[i] = (i >= 0 ? '/' : path[i]);
	ls_insert_elem(arg, dir, ((i == 0 ? "/" : tmp)));
	free(tmp);
	closedir(d);
}

static t_list	*nodir_inpath(char *path, char *flag, char *str)
{
	size_t			i;
	DIR				*d;
	struct dirent	*dir;
	t_list			*arg;

	i = 0;
	arg = NULL;
	if (illegal_opt(path) == 0)
		return (NULL);
	i = ft_strrchr(path, 47);
	(i != 0) ? path[i] = '\0' : 0;
	if (!(d = opendir((i == 0) ? "." : path)))
		return (NULL);
	(i != 0) ? path = path + i + 1 : 0;
	while ((dir = readdir(d)) != NULL && (ft_strcmp(dir->d_name, path)))
		;
	closedir(d);
	if (dir == NULL)
		return (error_msg(str));
	*flag |= F_A;
	(i != 0) ? path -= i + 1 : 0;
	str = ls_create_fp((i == 0 ? "." : path));
	ls_insert_elem(&arg, dir, str);
	(i != 0) ? path[i] = '/' : 0;
	return (arg);
}

int				ft_ls(t_param *p, char flag, t_pos t)
{
	t_list			*arg;
	DIR				*d;
	char			*str;

	arg = NULL;
	str = NULL;
	if (!(d = opendir(p->path)))
	{
		str = ft_strdup(p->path);
		if (!(arg = nodir_inpath(p->path, &flag, str)))
		{
			free(str);
			return (0);
		}
	}
	else
		launcher_two(d, &flag, p, &arg);
	if (str)
		free(str);
	ft_ls_two(arg, flag, p, t);
	return (1);
}

void			ft_sl(int i, char *av[], char flag)
{
	t_pos		t;
	t_param		*l1;
	t_param		*tmp;

	l1 = NULL;
	t.x = (av[i] && av[i + 1] ? 1 : 0);
	t.z = 0;
	while (av[i] && ++t.z > 0)
		l1 = param_to_list(av[i++], &l1);
	if (l1)
		ascii_param(&l1);
	tmp = l1;
	t.y = 1;
	if (t.z > 0)
		launcher_one(t, l1, flag);
	else
	{
		l1 = param_to_list(".", &l1);
		tmp = l1;
		ft_ls(l1, flag, t);
	}
	ft_lstdel_param(&tmp);
}
