/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 08:30:30 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/13 14:44:32 by tmeyer           ###   ########.fr       */
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
	char	tmp[1024];	//TO REMOVE

	(void)tmp; // FOR NOW
	if (!ft_strcmp(tab[0], "exit"))
		return (0);
	else if (!ft_strcmp(tab[0], "env"))
		print_env(environ->env);
	//	else if (!ft_strcmp(tab[0], "cd"))
	//	{
	//		ft_cd(tab, envp);
	//		getcwd(tmp, 1024);
	//		ft_putendl(tmp);
	//	}
	else if (!ft_strcmp(tab[0], "setenv"))
		environ->env = ft_setenv(tab[1], tab[2], environ->env);
	else if (!ft_strcmp(tab[0], "unsetenv"))
		environ->env = ft_unsetenv(tab[1], environ->env);
	else
		return (-1);
	return (1);
}

int				interpretor(char **tab, t_env *environ)
{
	int i;
	int k;

	if (!tab || !tab[0])
		return (-1);
	i = 0;
	if ((k = check_builtins(tab, environ)) == 0)
		return (0);
	tab = ft_freetab_char(tab);
	return (k == 0 ? 0 : 1);
}
