/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:55:17 by tmeyer            #+#    #+#             */
/*   Updated: 2019/04/03 12:35:20 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*plus_one(char *var)
{
	int		i;
	char	*tmp;
	char	*str;

	i = ft_atoi(ft_strchr(var, '=') + 1) + 1;
	tmp = ft_itoa(i);
	str = ft_strjoin("SHLVL=", tmp);
	free(tmp);
	return (str);
}

static t_env	*complete(t_env *environ, char *envp[], char *shell)
{
	int i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4))
		i++;
	environ->pwd = ft_strdup(envp[i]);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "SHLVL=", 6))
		i++;
	environ->shlvl = plus_one(envp[i]);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "OLDPWD=", 7))
		i++;
	environ->oldpwd = ft_strdup(envp[i]);
	i = 0;
	environ->prev = NULL;
	environ->env = ft_setenv("SHELL", shell, environ->env);
	ft_putenv(environ->shlvl, environ->env);
	return (environ);
}

static t_env	*check_environ(char *envp[], char *shell)
{
	t_env	*environ;
	int		i;

	i = 0;
	environ = NULL;
	if (!(environ = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	while (envp && envp[i])
		i++;
	if (i == 0)
		environ = create_env(environ);
	else
	{
		if (!(environ->env = (char**)malloc(sizeof(char*) * (i + 1))))
			return (NULL);
		i = -1;
		while (envp[++i])
			environ->env[i] = ft_strdup(envp[i]);
		environ->env[i] = NULL;
		environ = complete(environ, envp, shell);
	}
	return (environ);
}

static char		**arguments(t_env *environ)
{
	int		ret;
	char	*str;
	char	*tmp;
	char	*line;
	char	**command;

	line = NULL;
	command = NULL;
	str = NULL;
	ret = 0;
	while (!ret && get_command(0, &line))
	{
		tmp = ft_strdup(str);
		free(str);
		ret = check_line(&line);
		str = ft_strjoin((const char*)tmp, (const char*)line);
		ft_memdel((void**)&tmp);
		ft_memdel((void**)&line);
	}
	if (str && ft_strcmp(str, "") && (ret = check_str(&str, environ)) == 1)
		command = ft_strsplit(str, ';');
	ft_memdel((void**)&str);
	if (ret == ERROR_PARSE)
		ft_putendl_fd("minishell: syntax error near unexpected token ';'", 2);
	return (command);
}

int				main(int ac, char *av[], char *envp[])
{
	char	**command;
	int		i;
	t_env	*environ;

	if (!isatty(0))
		return (0);
	(void)ac;
	i = 0;
	command = NULL;
	environ = check_environ(envp, av[0]);
	while (1)
	{
		if (command == NULL)
			ft_putstr("$> ");
		if (command == NULL && (!(command = arguments(environ)) || !command[0]))
			continue ;
		if (interpretor(ft_split_whitespaces_m(command[i]), environ) == 0)
			break ;
		if ((!command[i] || !command[++i]) && !(i = 0))
			command = ft_freetab_char(command);
	}
	command = ft_freetab_char(command);
	environ = free_struct(environ);
	return (1);
}
