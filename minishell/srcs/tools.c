/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:47:29 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/13 14:44:31 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_str(char *str)
{
	int i;
	int j;

	i = -1;
	while (str[++i] != '\0')
	{
		j = 2;
		if (str[i] == ';')
		{
			if (str[i + 1] == ';')	
				return (0);
			else if (str[i + 1] <= 32 && str[i + 1] != '\0')
			{
				while (str[i + j] <= 32 && str[i + j] != '\0')
					j++;
				if (str[i + j] == ';')
				   return (0);	
			}
		}
		i++;	
	}
	return (1);
}

void	ccbis(char **command, int *flag, int i)
{
	int j;

	j = 0;	
	while (command[i][j] != '\0')
	{
		if (command[i][j++] > 32)
		{
			*flag = 1;
			return ;
		}
	}
}

char	**check_command(char **command)
{
	int i;
	int flag;

	i = -1;
	while (command && command[++i])
	{
		flag = 0;
		ccbis(command, &flag, i);
		if (!flag)
			break ;
	}
	if (!flag)
	{
		command = ft_freetab_char(command);
		ft_putendl_fd("parse error near unexcpeted toxen ';'", 2);
		return (NULL);
	}
	return (command);
}

t_env		*free_struct(t_env *environ)
{
	environ->env = ft_freetab_char(environ->env);
	free(environ->PWD);
	environ->PWD = NULL;
	free(environ->SHLVL);
	environ->SHLVL = NULL;
	free(environ->prev);
	environ->prev = NULL;
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
