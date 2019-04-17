/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:02:56 by tmeyer            #+#    #+#             */
/*   Updated: 2019/04/05 09:50:45 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*find_match(t_env *environ, char *str, int i, int j)
{
	int		k;
	char	*tmp;

	tmp = ft_strjoin(&str[i - j], "=");
	k = 0;
	while (environ->env[k] && ft_strncmp(environ->env[k], tmp, ft_strlen(tmp)))
		k++;
	ft_memdel((void**)&tmp);
	if (!environ->env[k])
		return (ft_strdup("\0"));
	return (ft_strdup(ft_strchr(environ->env[k], '=') + 1));
}

char			*str_replace_str(char **str, char *sub, int i, int j)
{
	int		k;
	int		l;
	char	*tmp;

	if (!sub)
	{
		ft_memdel((void**)str);
		return (NULL);
	}
	k = ft_strlen(*str) - j + ft_strlen(sub);
	if (!(tmp = (char*)ft_memalloc(k + 2)))
		return (*str);
	l = -1;
	while (++l < i - j + 1)
		tmp[l] = str[0][l];
	k = 0;
	while (sub[k] != '\0')
		tmp[l++] = sub[k++];
	if (str[0][i] != '\0')
		i++;
	while (str[0][i] != '\0')
		tmp[l++] = str[0][i++];
	ft_memdel((void**)str);
	return (tmp);
}

static int		expone(char **str, t_env *environ, int *i)
{
	if (str[0][*i + 1] == '/' || str[0][*i + 1] <= 32
			|| str[0][*i + 1] == ';' || str[0][*i + 1] == '$')
	{
		if (expone_tilde(str, environ, i))
			return (ERROR_HOME);
	}
	else if (str[0][*i + 1] == '-' && (str[0][*i + 2] == '/'
				|| str[0][*i + 2] == ';' || str[0][*i + 2] <= 32
				|| str[0][*i + 2] == '$'))
	{
		if (expone_tilde_tw(str, environ, i))
			return (ERROR_OLDPWD);
	}
	else if (str[0][*i + 1] == '+' && (str[0][*i + 2] == '/'
				|| str[0][*i + 2] <= 32 || str[0][*i + 2] == ';'
				|| str[0][*i + 2] == '$'))
	{
		if (expone_tilde_tr(str, environ, i))
			return (ERROR_PWD);
	}
	return (-1);
}

static void		exptwo(char **str, t_env *environ, int *i)
{
	int		j;
	char	*sub;

	*i += 1;
	j = 0;
	sub = NULL;
	while (str[0][*i] != '\0' && ((str[0][*i] >= 'A' && str[0][*i] <= 'Z')
				|| (str[0][*i] >= 'a' && str[0][*i] <= 'z')
				|| str[0][*i] == '_'))
	{
		*i += 1;
		j++;
	}
	sub = find_match(environ, *str, *i, j);
	*str = str_replace_str(str, sub, *i - 1, j + 1);
	*i = *i - j - 2 + ft_strlen(sub);
	free(sub);
	sub = NULL;
}

int				expantions(char **str, t_env *environ)
{
	int		i;
	int		k;

	i = 0;
	while (str[0][i] != '\0')
	{
		if (str[0][i] == '~' && (i == 0 || str[0][i - 1] <= 32))
		{
			if ((k = expone(str, environ, &i)) != -1)
				return (k);
		}
		if (str[0][i] == '$' && (i == 0 || str[0][i - 1] != 39))
			exptwo(str, environ, &i);
		if (str[0][i] != '\0')
			i++;
	}
	return (0);
}
