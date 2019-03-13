/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <tmeyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:45:39 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/19 10:20:36 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dir(char *path)
{
	DIR *d;

	if (!(d = opendir(path)))
		return (0);
	closedir(d);
	return (1);
}

void	swap(t_list *a, t_list *b)
{
	t_list temp;

	temp.buf = a->buf;
	temp.pw = a->pw;
	temp.gr = a->gr;
	temp.name = a->name;
	temp.path = a->path;
	a->buf = b->buf;
	a->pw = b->pw;
	a->gr = b->gr;
	a->name = b->name;
	a->path = b->path;
	b->buf = temp.buf;
	b->pw = temp.pw;
	b->gr = temp.gr;
	b->name = temp.name;
	b->path = temp.path;
}

size_t	ft_strrchr(char *s, int c)
{
	size_t i;

	i = ft_strl(s);
	if (s[i] == c)
		return (i);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
			return (i);
	}
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	if (!src)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strl(src) + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
