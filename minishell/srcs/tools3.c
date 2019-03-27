/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 07:36:41 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 13:31:57 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*add_newline(char *line)
{
	char *tmp;

	tmp = ft_strdup(line);
	free(line);
	line = ft_strjoin((const char*)tmp, "\n");
	free(tmp);
	tmp = NULL;
	return (line);
}

int				check_line(char **line)
{
	int			i;
	static int	k = 1;
	static char	c = '\0';

	i = 0;
	if (!*line)
		return (0);
	while (line[0][i] != '\0')
	{
		if ((line[0][i] == 34 || line[0][i] == 39)
				&& (c == '\0' || c == line[0][i]))
		{
			k = (k == 1 ? 0 : 1);
			c = (k == 0 ? line[0][i] : '\0');
		}
		i++;
	}
	if (k == 0)
	{
		*line = add_newline(*line);
		write(1, "> ", 1);
	}
	return (k);
}

int				error_code(int code)
{
	if (code == ERROR_HOME)
		ft_putendl_fd("NO HOME SET", 2);
	else if (code == ERROR_OLDPWD)
		ft_putendl_fd("NO OLDPWD SET", 2);
	else if (code == ERROR_PWD)
		ft_putendl_fd("NO PWD SET", 2);
	return (ERROR_ENV);
}
