/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:37:23 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/19 20:23:39 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_printrights(t_list *arg, int maj, int min)
{
	acl_t		acl;
	acl_entry_t	ext;

	acl = acl_get_link_np(arg->path, ACL_TYPE_EXTENDED);
	acl_get_entry(acl, ACL_FIRST_ENTRY, &ext);
	ft_only_rights(arg);
	if ((arg->buf.st_mode & S_ISVTX))
		ft_printf((arg->buf.st_mode & S_IXOTH) ? "t" : "T");
	else
		ft_printf((arg->buf.st_mode & S_IXOTH) ? "x" : "-");
	if (listxattr(arg->path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_printf("@  %d", arg->buf.st_nlink);
	else if (acl != NULL)
		ft_printf("+  %d", arg->buf.st_nlink);
	else
		ft_printf("  %d", arg->buf.st_nlink);
	if (((arg->buf.st_mode & S_IFMT) == S_IFCHR))
		ft_printf("  %s %s  %d, %d", arg->pw, arg->gr, maj, min);
	else
		ft_printf("  %s %s  %d", arg->pw, arg->gr, arg->buf.st_size);
	if (acl)
		acl_free(acl);
}

static void	ft_print_time(t_list *arg)
{
	time_t	isold;
	time_t	isnew;

	isold = time(&isold);
	isnew = isold;
	isold -= 15780000;
	isnew += 15780000;
	if (isold < arg->buf.st_mtime && isnew > arg->buf.st_mtime)
		ft_printf(" %.12s", ctime(&arg->buf.st_mtime) + 4);
	else
	{
		ft_printf(" %.7s", ctime(&arg->buf.st_mtime) + 4);
		if (ft_strcmp(ctime(&arg->buf.st_mtime) + 20, "    10000\n") == 0)
			ft_printf(" %.5s", ctime(&arg->buf.st_mtime) + 24);
		else
			ft_printf(" %.4s", ctime(&arg->buf.st_mtime) + 20);
	}
}

void		ft_printperm(t_list *arg, char flag, t_param *p)
{
	struct stat	buf;
	intmax_t	maj;
	intmax_t	min;
	char		buff[PATH_MAX];

	if ((!(flag & F_A) && arg->name[0] == '.') || arg->buf.st_mode == 0)
		return ;
	maj = ((int)(((unsigned int)(arg->buf.st_rdev) >> 24) & 0xff));
	min = ((int)(arg->buf.st_rdev & 0xff));
	ft_printrights(arg, (int)maj, (int)min);
	ft_print_time(arg);
	ft_printf(" %s%s%s", ft_colors(flag, arg->buf.st_mode),
			(p->type != 'd' && p->given == 1 ? p->path : arg->name), C_RESET);
	if (((arg->buf.st_mode & S_IFMT) == S_IFLNK))
	{
		(lstat(arg->path, &buf) == -1) ? exit(0) : 0;
		((min = readlink(arg->path, buff, sizeof(buff) - 1)) != -1) ?
			buff[min] = '\0' : 0;
		(min != -1) ? ft_printf(" -> %s", buff) : 0;
	}
	ft_printf("\n");
}

static void	check_av(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			write(2, "ft_ls: fts_open: No such file or directory\n", 43);
			exit(0);
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	int		i;
	char	flag;

	i = 1;
	flag = '\0';
	while (av[i])
	{
		check_av(av);
		if (ft_strcmp(av[i], "--") == 0)
		{
			i++;
			break ;
		}
		if (av[i][0] == '-' && av[i][1] != 0)
			check_flags(av[i] + 1, &flag);
		else
			break ;
		i++;
	}
	ft_sl(i, av, flag);
	(void)ac;
	return (0);
}
