/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:47:29 by tmeyer            #+#    #+#             */
/*   Updated: 2019/04/01 11:16:04 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_str(char **str, t_env *environ)
{
	int i;
	int j;

	i = -1;
	while (str[0][++i] != '\0')
	{
		j = 2;
		if (str[0][i] == ';')
		{
			if (str[0][i + 1] == ';')
				return (ERROR_PARSE);
			else if (str[0][i + 1] <= 32 && str[0][i + 1] != '\0')
			{
				while (str[0][i + j] <= 32 && str[0][i + j] != '\0')
					j++;
				if (str[0][i + j] == ';')
					return (ERROR_PARSE);
			}
		}
	}
	if ((j = expantions(str, environ)) > 0)
		return (error_code(j));
	return (1);
}

t_env		*free_struct(t_env *environ)
{
	environ->env = ft_freetab_char(environ->env);
	free(environ->pwd);
	environ->pwd = NULL;
	free(environ->shlvl);
	environ->shlvl = NULL;
	free(environ->prev);
	environ->prev = NULL;
	free(environ->oldpwd);
	environ->oldpwd = NULL;
	free(environ);
	environ = NULL;
	return (environ);
}

char		**ft_putenv(char *var, char **env)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr(var, '=') + 1;
	if (tmp == NULL)
		return (env);
	while (var[i] != '=' && var[i] != '\0')
		i++;
	if (var[i] == '=')
		var[i] = '\0';
	env = ft_setenv(var, tmp, env);
	var[i] = '=';
	tmp = NULL;
	return (env);
}
