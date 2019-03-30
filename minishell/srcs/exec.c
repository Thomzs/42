/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:50:53 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 14:44:59 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_exec(char *exe, char **tab, t_env *environ)
{
    char	**arg;
    char	**envp;
    int		status;
    int		k;
    pid_t	pid;

    arg = ft_copytab_char(tab);
    envp = ft_copytab_char(environ->env);
    k = 1;
    if ((pid = fork()) == -1)
	k = 0;
    else if (pid == 0)
    {
	if (execve(exe, arg, envp) == -1)
	    k = 0;
    }
    else
	wait(&status);
    arg = ft_freetab_char(arg);
    envp = ft_freetab_char(envp);
    free(environ->prev);
    environ->prev = ft_strjoin("_=", exe);
    environ->env = ft_setenv("_", exe, environ->env);
    return (k);
}

static char		*search_inpath(char *arg, t_env *environ, char **tmp)
{
    struct dirent	*dir;
    char			**path;
    DIR				*d;
    int				i;

    i = -1;
    if (!(path = ft_strsplit(ft_getenv("PATH", environ->env), ':')))
	return (NULL);
    while (path && path[++i])
    {
	if (!(d = opendir(path[i])))
	{
	    path = ft_freetab_char(path);
	    return (NULL);
	}
	while ((dir = readdir(d)) && ft_strcmp(dir->d_name, arg))
	    continue ;
	closedir(d);
	if (dir != NULL)
	    break ;
    }
    ft_memdel((void**)tmp);
    *tmp = (path[i] ? ft_strjoin(path[i], "/") : NULL);
    path = ft_freetab_char(path);
    return (dir == NULL || tmp == NULL ? NULL : arg);
}

static char		*search_exe(char *arg, char **tmp)
{
    struct dirent	*dir;
    char			*exe;
    DIR				*d;
    int				i;
    char			c;

    exe = ft_strrchr(arg, '/') + 1;
    i = ft_strlen(arg) - ft_strlen(exe) - 1;
    arg[i] = '\0';
    if (!(d = opendir(arg)))
	return (NULL);
    while ((dir = readdir(d)) && ft_strcmp(dir->d_name, exe))
	continue ;
    closedir(d);
    arg[i] = '/';
    c = arg[i + 1];
    arg[i + 1] = '\0';
    ft_memdel((void**)tmp);
    *tmp = ft_strdup(arg);
    arg[i + 1] = c;
    return (dir == NULL || tmp == NULL ? NULL : exe);
}

static int		check_binary_path(char *exe)
{
    struct stat	sb;

    if (lstat(exe, &sb) == -1)
	return (0);
    if ((sb.st_mode & S_IFMT) == S_IFDIR)
    {
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(exe, 2);
	ft_putendl_fd(": is a directory", 2);
	return (0);
    }
    if ((sb.st_mode & S_IFMT) != S_IFREG)
	return (0);
    if (!(sb.st_mode & IS_EXEC))
	return (0);
    return (1);
}

int				check_exec(char **tab, t_env *environ)
{
    char *path;
    char *exe;
    char *avz;
    char *tmp;

    avz = ft_strdup(tab[0]);
    path = NULL;
    if (!((path = ft_strdup(ft_strchr(avz, '/')))))
	exe = search_inpath(avz, environ, &path);
    else
	exe = search_exe(avz, &path);
    tmp = ft_strjoin(path, exe);
    ft_memdel((void**)&avz);
    ft_memdel((void**)&path);
    if (!tmp || !check_binary_path(tmp))
    {
	ft_memdel((void**)&tmp);
	return (-1);
    }
    ft_exec(tmp, tab, environ);
    ft_memdel((void**)&tmp);
    return (1);
}
