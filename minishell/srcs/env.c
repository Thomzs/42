/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:47:13 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/13 10:20:47 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				**ft_unsetenv(char *var, char **env)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = ft_strlen(var);
	j = 0;
	k = 1;
	tmp = ft_strjoin(var, "=");
	while (env[j] && ft_strncmp(env[j], tmp, i))
		j++;
	if (env[j])
	{
		free(env[j]);
		while (env[j + k])
			k++;
		env[j] = ft_strdup(env[j + k - 1]);
		free(env[j + k - 1]);
		env[j + k - 1] = NULL;
	}
	free(tmp);
	tmp = NULL;
	return (env);	
}

static char			**insert_var(char *content, char *tmp, char **env)
{
	int		i;
	char	**tab;

	i = 0;
	while (env[i])
		i++;
	if (!(tab = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = -1;
	while (env[++i])
		tab[i] = ft_strdup(env[i]);
	tab[i] = ft_strjoin(tmp, content);
	tab[++i] = NULL;
	env = ft_freetab_char(env);
	return (tab);
}

char				**ft_setenv(char *var, char *content, char **env)
{
	int i;
	int j;
	char *tmp;

	j = 0;
	i = ft_strlen(var);
	tmp = ft_strjoin(var, "=");
	while (env[j] && ft_strncmp(env[j], tmp, i + 1))
		j++;
	if (!env[j])
		env = insert_var(content, tmp, env);
	else
	{
		free(env[j]);
		env[j] = ft_strjoin(tmp, content);
	}
	free(tmp);
	tmp = NULL;
	return (env);
}

static t_env		*get_pwd(t_env *environ)
{
	int i;
	char *buf;

	i = 1;
	buf = NULL;
	while (!buf)
	{
		if (!(buf = (char*)malloc(sizeof(char) * (i * 1024))))
			return (NULL);
		if (!(buf = getcwd(buf, i * 1024)))
			i++;
	}
	environ->PWD = ft_strjoin("PWD=", buf);
	free(buf);
	return (environ);
}

t_env				*create_env(t_env *environ)
{
	environ->env = NULL;
	environ->PWD = NULL;
	environ->SHLVL = ft_strdup("SHLVL=1");
	environ->prev = NULL;
	environ = get_pwd(environ);
	if (!(environ->env = (char**)malloc(sizeof(char*) * 4)))
		return (NULL);
	environ->env[0] = ft_strdup(environ->PWD);
	environ->env[1] = ft_strdup(environ->SHLVL);
	environ->env[2] = ft_strdup("-=");
	environ->env[3] = NULL;
	return (environ);
}
