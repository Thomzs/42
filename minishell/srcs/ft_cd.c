/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:24:48 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 16:19:52 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_dc(char *str, t_env *environ)
{
	if (environ->pwd)
	{
		free(environ->oldpwd);
		environ->oldpwd = ft_strjoin("OLDPWD=", environ->pwd + 4);
		ft_memdel((void**)&environ->pwd);
	}
	if (chdir(str) == -1 || !(environ->pwd = get_pwd()))
	{
		ft_memdel((void**)&str);
		return (1);
	}
	if (environ->pwd)
	{
		environ->env = ft_setenv("PWD", environ->pwd + 4, environ->env);
		if (environ->oldpwd)
			environ->env = ft_setenv("OLDPWD",
					environ->oldpwd + 7, environ->env);
	}
	ft_memdel((void**)&str);
	return (0);
}

static int		check_path(int k, struct stat sb, char *str)
{
	if (k == 0 && (sb.st_mode & S_IFMT) != S_IFDIR)
	{
		ft_putstr_fd("cd: not a directory: ", 2);
		ft_putendl_fd(str, 2);
		return (1);
	}
	else if (k < 0)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(str, 2);
		return (1);
	}
	else if (!(sb.st_mode & S_ISVTX) && !(sb.st_mode & S_IXOTH))
	{
		ft_putstr_fd("cd: permission denied: ", 2);
		ft_putendl_fd(str, 2);
		return (1);
	}
	return (0);
}

int				ft_cd(char **tab, t_env *environ)
{
	char		*str;
	int			k;
	struct stat sb;

	if (tab[1] && tab[2])
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return (1);
	}
	str = ft_strdup(tab[1] ? tab[1] : ft_getenv("HOME", environ->env));
	if (!str)
	{
		ft_putendl_fd("cd: NO HOME SET", 2);
		return (1);
	}
	k = lstat(str, &sb);
	if (check_path(k, sb, str))
	{
		ft_memdel((void**)&str);
		return (1);
	}
	else
		return (ft_dc(str, environ));
}
