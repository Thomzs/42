/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:30:08 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/19 20:08:41 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_colors(char flag, mode_t mode)
{
	if (!(flag & F_G))
		return (C_RESET);
	if ((mode & S_IFMT) == S_IFDIR)
		return (C_CYAN);
	if ((mode & S_IFMT) == S_IFLNK)
		return (C_MAGENTA);
	if ((mode & S_IFMT) == S_IFREG)
		return ((mode & IS_EXEC) ? C_RED : C_RESET);
	return (C_RESET);
}

void				illegal_opt_path(char *path)
{
	char *str;

	if (errno)
	{
		str = ft_strjoin("ft_ls: ", path);
		perror(str);
		free(str);
	}
}

static t_param		*ft_lstdelone_param(t_param *target)
{
	t_param *tmp;
	t_param *next;

	tmp = target;
	if (tmp)
	{
		next = target->next;
		free(target->path);
		if (target)
			free(target);
		return (next);
	}
	return (NULL);
}

void				ft_lstdel_param(t_param **alst)
{
	if (*alst != NULL)
	{
		ft_lstdel_param(&((*alst)->next));
		ft_lstdelone_param(*alst);
	}
}

int					check_path(char *path)
{
	if (path[0] == '.' && path[1] == '\0')
		return (0);
	if (path[0] == '.' && path[1] == '.' && path[2] == '\0')
		return (0);
	return (1);
}
