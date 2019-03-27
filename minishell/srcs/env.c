/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:47:13 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 16:21:19 by tmeyer           ###   ########.fr       */
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
	ft_memdel((void**)&tmp);
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
	if (tmp && content)
		tab[i++] = ft_strjoin(tmp, content);
	tab[i] = NULL;
	env = ft_freetab_char(env);
	return (tab);
}

char				**ft_setenv(char *var, char *content, char **env)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = ft_strlen(var);
	tmp = ft_strjoin(var, "=");
	while (env && env[j] && ft_strncmp(env[j], tmp, i + 1))
		j++;
	if (!env[j])
		env = insert_var(content, tmp, env);
	else
	{
		free(env[j]);
		env[j] = ft_strjoin(tmp, content);
	}
	ft_memdel((void**)&tmp);
	return (env);
}

char				*get_pwd(void)
{
	int			i;
	char		*buf;
	char		*str;

	i = 1;
	buf = NULL;
	str = NULL;
	while (!buf)
	{
		if (!(buf = (char*)malloc(sizeof(char) * (256))))
			return (NULL);
		if (!(buf = getcwd(buf, 256)))
		{
			ft_putendl_fd("minishell: cannot access asked directory", 2);
			return (NULL);
		}
	}
	str = ft_strjoin("PWD=", buf);
	ft_memdel((void**)&buf);
	return (str);
}

t_env				*create_env(t_env *environ)
{
	int i;

	i = 0;
	environ->env = NULL;
	environ->pwd = NULL;
	environ->shlvl = ft_strdup("SHLVL=1");
	environ->oldpwd = NULL;
	environ->prev = NULL;
	environ->home = NULL;
	environ->pwd = get_pwd();
	if (!(environ->env = (char**)malloc(sizeof(char*)
					* (environ->pwd ? 4 : 3))))
		return (NULL);
	environ->env[i++] = ft_strdup(environ->shlvl);
	environ->env[i++] = ft_strdup("_=");
	if (environ->pwd)
		environ->env[i++] = ft_strdup(environ->pwd);
	environ->env[i] = NULL;
	return (environ);
}
