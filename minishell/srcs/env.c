/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:47:13 by tmeyer            #+#    #+#             */
/*   Updated: 2019/04/02 07:46:25 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				**ft_unsetenv(char *var, char **env)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	j = 0;
	k = 0;
	tmp = ft_strjoin(var, "=");
	i = ft_strlen(var);
	while (env[j] && ft_strncmp(env[j], tmp, i))
		j++;
	ft_memdel((void**)&tmp);
	if (!env[j])
		return (env);
	while (env[k])
		k++;
	if (--k == j)
		ft_memdel((void**)&env[j]);
	else
	{
		ft_memdel((void**)&env[j]);
		env[j] = ft_strdup(env[k]);
		ft_memdel((void**)&env[k]);
	}
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
	char		*tmp;
	char		*str;

	i = 1;
	buf = NULL;
	str = NULL;
	if (!(buf = (char*)ft_memalloc(256)))
		return (NULL);
	if (!(tmp = getcwd(buf, 256)))
	{
		ft_memdel((void**)&buf);
		tmp = NULL;
		ft_putendl_fd("minishell: cannot access asked directory", 2);
		return (NULL);
	}
	str = ft_strjoin("PWD=", tmp);
	tmp = NULL;
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
