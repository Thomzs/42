/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:55:17 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/13 14:44:35 by tmeyer           ###   ########.fr       */
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

static t_env	*complete(t_env *environ, char *envp[], char *SHELL)
{
	int i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PWD=", 4))
		i++;
	environ->PWD = ft_strdup(envp[i]);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "SHLVL=", 6))
		i++;
	environ->SHLVL = plus_one(envp[i]);
	environ->prev = NULL;
	ft_setenv("SHELL", SHELL, environ->env);
	ft_putenv(environ->SHLVL, environ->env);
	return (environ);
}

static t_env	*check_environ(char *envp[], char *SHELL)
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
		environ = complete(environ, envp, SHELL);
	}
	return (environ);
}

static char		**arguments(void)
{
	int		ret;
	char	buf[2];
	char	*str;
	char	*tmp;
	char	**command;

	command = NULL;
	str = NULL;
	buf[1] = '\0';
	while ((ret = read(0, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
			break ;
		tmp = ft_strdup(str);
		free(str);
		str = ft_strjoin((const char*)tmp, (const char*)buf);
		free(tmp);
	}
	if (str && (ret = check_str(str)))
		command = ft_strsplit(str, ';');
	if (!ret)
		ft_putendl_fd("minishell: syntax error near unexpected token ';'", 2);
	free(str);
	str = NULL;
	return (command);
}

int				main(int ac, char *av[], char *envp[])
{
	char	**command;
	int		i;
	t_env	*environ;

	(void)ac;
	i = 0;
	command = NULL;
	environ = check_environ(envp, av[0]);
	while (1)
	{
		if (command == NULL)
			ft_putstr("$> ");
		if (command == NULL && !(command = arguments()))
			continue ;
//		environ = put_command(command[i]);		TO DO
		if (interpretor(ft_split_whitespaces(command[i]), environ) == 0)
			break ;
		if (!command[++i] && !(i = 0))
			command = ft_freetab_char(command);
	}
	command = ft_freetab_char(command);
	environ = free_struct(environ);
	return (1);
}
