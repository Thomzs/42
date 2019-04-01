/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 08:30:30 by tmeyer            #+#    #+#             */
/*   Updated: 2019/04/01 14:25:55 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_env(char *env[])
{
	int i;

	i = 0;
	while (env && env[i])
		ft_putendl(env[i++]);
}

static int		check_builtins(char **tab, t_env *environ)
{
	if (!ft_strcmp(tab[0], "exit"))
		return (0);
	else if (!ft_strcmp(tab[0], "env"))
		print_env(environ->env);
	else if (!ft_strcmp(tab[0], "cd"))
		ft_cd(tab, environ);
	else if (!ft_strcmp(tab[0], "setenv") && tab[1] && tab[2])
		environ->env = ft_setenv(tab[1], tab[2], environ->env);
	else if (!ft_strcmp(tab[0], "unsetenv") && tab[1])
		environ->env = ft_unsetenv(tab[1], environ->env);
	else if (!ft_strcmp(tab[0], "echo"))
		ft_echo(tab);
	else
		return (-1);
	return (1);
}

int				interpretor(char **tab, t_env *environ)
{
	int i;
	int k;

	if (!tab || !tab[0])
	{
		tab = ft_freetab_char(tab);
		return (-1);
	}
	i = 0;
	k = check_builtins(tab, environ);
	if (k == -1)
		k = check_exec(tab, environ);
	if (k == -1)
	{
		ft_putstr_fd("minishell: no command found: ", 2);
		ft_putendl_fd(tab[0], 2);
	}
	tab = ft_freetab_char(tab);
	return (k == 0 ? 0 : 1);
}
