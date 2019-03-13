/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rwx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 21:46:51 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/19 10:26:15 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rwx_one(t_list *arg)
{
	ft_printf((arg->buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((arg->buf.st_mode & S_IWUSR) ? "w" : "-");
	if ((arg->buf.st_mode & S_IXUSR) && (arg->buf.st_mode & S_ISUID))
		ft_printf("s");
	else if (!(arg->buf.st_mode & S_IXUSR) && (arg->buf.st_mode & S_ISUID))
		ft_printf("S");
	else if ((arg->buf.st_mode & S_IXUSR) && !(arg->buf.st_mode & S_ISUID))
		ft_printf("x");
	else
		ft_printf("-");
}

void	ft_rwx_two(t_list *arg)
{
	ft_printf((arg->buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((arg->buf.st_mode & S_IWGRP) ? "w" : "-");
	if ((arg->buf.st_mode & S_IXGRP) && (arg->buf.st_mode & S_ISGID))
		ft_printf("s");
	else if (!(arg->buf.st_mode & S_IXGRP) && (arg->buf.st_mode & S_ISGID))
		ft_printf("S");
	else if ((arg->buf.st_mode & S_IXGRP) && !(arg->buf.st_mode & S_ISGID))
		ft_printf("x");
	else
		ft_printf("-");
}

void	ft_printpermtwo(t_list *arg, char *path, char flag)
{
	if (!(flag & F_A) && arg->name[0] == '.')
		return ;
	if (is_dir(path))
		ft_printf("%s%s%s\n", ft_colors(flag, arg->buf.st_mode),
				arg->name, C_RESET);
	else
		ft_printf("%s%s%s\n", ft_colors(flag, arg->buf.st_mode), path, C_RESET);
}
