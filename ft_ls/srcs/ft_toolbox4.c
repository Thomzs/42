/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:08:52 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/19 20:22:53 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_only_rights(t_list *arg)
{
	(((arg->buf.st_mode & S_IFMT) == S_IFBLK)) ? ft_printf("b") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFCHR)) ? ft_printf("c") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFDIR)) ? ft_printf("d") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFLNK)) ? ft_printf("l") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFSOCK)) ? ft_printf("s") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFIFO)) ? ft_printf("p") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFREG)) ? ft_printf("-") : 0;
	ft_rwx_one(arg);
	ft_rwx_two(arg);
	ft_printf((arg->buf.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((arg->buf.st_mode & S_IWOTH) ? "w" : "-");
}
