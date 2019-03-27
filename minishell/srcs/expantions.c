/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:02:56 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 14:52:56 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*find_match(t_env *environ, char *str, int i, int j)
{
	int k;

	k = 0;
	while (environ->env[k] && ft_strncmp(environ->env[k], &str[i - j], j))
		k++;
	if (!environ->env[k])
		return (ft_strdup("\0"));
	return (ft_strdup(ft_strchr(environ->env[k], '=') + 1));
}

static char		*str_replace_str(char *str, char *sub, int i, int j)
{
	int		k;
	int		l;
	char	*tmp;

	if (!sub)
		return (NULL);
	k = ft_strlen(str) - j + ft_strlen(sub);
	if (!(tmp = (char*)ft_memalloc(k + 2)))
		return (str);
	l = -1;
	while (++l < i - j + 1)
		tmp[l] = str[l];
	k = 0;
	while (sub[k] != '\0')
		tmp[l++] = sub[k++];
	if (str[i] != '\0')
		i++;
	while (str[i] != '\0')
		tmp[l++] = str[i++];
	free(str);
	str = NULL;
	return (tmp);
}

static int		expone(char **str, t_env *environ, int *i)
{
	if (str[0][*i + 1] == '/' || str[0][*i + 1] <= 32 || str[0][*i + 1] == '$')
	{
		if (!environ->home
				|| !(*str = str_replace_str(*str, environ->home + 5, *i, 1)))
			return (ERROR_HOME);
		i += ft_strlen(environ->home + 5) - 1;
	}
	if (str[0][*i + 1] == '-' && (str[0][*i + 2] == '/'
				|| str[0][*i + 2] <= 32 || str[0][*i + 2] == '$'))
	{
		if (!environ->oldpwd
				|| !(*str = str_replace_str(*str, environ->oldpwd + 7,
						*i + 1, 2)))
			return (ERROR_OLDPWD);
		*i += ft_strlen(environ->oldpwd + 7) - 1;
	}
	else if (str[0][*i + 1] == '+' && (str[0][*i + 2] == '/'
				|| str[0][*i + 2] <= 32 || str[0][*i + 2] == '$'))
	{
		if (!environ->pwd ||
				!(*str = str_replace_str(*str, environ->pwd + 4, *i + 1, 2)))
			return (ERROR_PWD);
		*i += ft_strlen(environ->pwd + 4) - 1;
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
	*str = str_replace_str(*str, sub, *i, j + 2);
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
