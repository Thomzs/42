/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:27:28 by tmeyer            #+#    #+#             */
/*   Updated: 2018/12/03 10:56:44 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*rest(char **x, char *c, const int fd)
{
	if (c)
	{
		free(x[fd]);
		return (ft_strdup(""));
	}
	else
		return (x[fd]);
}

static char		*aux(const int fd, char *c, char *str, char **x)
{
	int		ret;
	char	*temp;
	char	buffer[BUFF_SIZE + 1];

	while (!c && (ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		temp = ft_strdup(str);
		free(str);
		str = ft_strnjoin(temp, buffer, ret);
		free(temp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (ret == -1)
	{
		free(x[fd]);
		free(str);
		return (NULL);
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	int			len;
	char		*str;
	char		*c;
	int			k;
	static char *x[4865];

	str = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || read(fd, str, 0))
		return (-1);
	c = (x[fd] ? ft_strchr(x[fd], '\n') : NULL);
	str = ((x[fd] && c) ? ft_strdup(x[fd]) : ft_strdup(""));
	x[fd] = ((x[fd]) ? rest(x, c, fd) : ft_strdup(""));
	if (!(str = aux(fd, c, str, x)))
		return (-1);
	c = ft_strchr(str, '\n');
	len = ((str && c) ? ft_strlen(c) : 0);
	*line = ft_strnjoin(x[fd], str, ft_strlen(str) - len);
	free(x[fd]);
	x[fd] = (c ? ft_strdup(c + 1) : ft_strdup(""));
	k = (*line == NULL ? -1 : 1);
	free(str);
	if (k == 0 || k == -1)
		free(x[fd]);
	return (!ft_strcmp(*line, "") && !ft_strcmp(x[fd], "")
			&& !(ft_strcmp(str, "")) ? 0 : k);
}
