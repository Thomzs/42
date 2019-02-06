/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:37:23 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/06 00:12:03 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern int errno;

void illegal_opt(char *path)
{
	ft_printf("ft_ls: %s\n", strerror(errno));
}

void illegal_flag(char op)
{
	ft_printf("ft_ls: %s\n", strerror(errno));
}


void 	ft_printperm(t_list *arg)
{
	struct stat buf;

	(((arg->buf.st_mode & S_IFMT) == S_IFBLK)) ? ft_printf("b") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFCHR)) ? ft_printf("c") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFDIR)) ? ft_printf("d") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFLNK)) ? ft_printf("l") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFSOCK)) ? ft_printf("s") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFIFO)) ? ft_printf("p") : 0;
	(((arg->buf.st_mode & S_IFMT) == S_IFREG)) ? ft_printf("-") : 0;
	ft_printf((arg->buf.st_mode & S_IRUSR) ? "r":"-");
	ft_printf((arg->buf.st_mode & S_IWUSR) ? "w":"-");
	ft_printf((arg->buf.st_mode & S_IXUSR) ? "x":"-");
	ft_printf((arg->buf.st_mode & S_IRGRP) ? "r":"-");
	ft_printf((arg->buf.st_mode & S_IWGRP) ? "w":"-");
	ft_printf((arg->buf.st_mode & S_IXGRP) ? "x":"-");
	ft_printf((arg->buf.st_mode & S_IROTH) ? "r":"-");
	ft_printf((arg->buf.st_mode & S_IWOTH) ? "w":"-");
	ft_printf((arg->buf.st_mode & S_IXOTH) ? "x":"-");
	(listxattr(arg->path, NULL, 0, XATTR_NOFOLLOW) > 0) ? ft_printf("@") : 0;
	ft_printf("    %s", arg->name);
	if (((arg->buf.st_mode & S_IFMT) == S_IFLNK))
	{
		if (stat(arg->path,&buf) == -1)
			exit(0);
		ft_printf(" -> SYMLINK");
	}
	ft_printf("\n");
}

void check_flags(char *from, char *to)
{
	int i;

	i = 0;
	while (from[i])
	{
		if (from[i] == 'l')
			*to |= F_L;
		else if (from[i] == 'a')
			*to |= F_A;
		else if (from[i] == 'r')
			*to |= F_RL;
		else if (from[i] == 't')
			*to |= F_T;
		else if (from[i] == 'R')
			*to |= F_RU;
		else
			illegal_flag(from[i]);
		i++;
	}
	if (from[0] == '\0')
		illegal_flag(' ');
}

int 	isflag(char flag)
{
	if (flag == 'a' || flag == 'r' || flag == 'l' || flag == 't' || flag == 'R')
		return (ISFLAG);
	return (0);
}

int main(int ac, char **av)
{
	int i;
	char 	flag;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-' && !(flag & PATHS) && av[i][1] != 0)
			check_flags(av[i] + 1, &flag);
		else
			break ;
		i++;
	}
	ft_sl(i, av, flag);
	(void)ac;
	return (0);
}
