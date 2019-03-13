/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 23:29:52 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/19 10:23:49 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t			ft_strl(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		pos;
	size_t	size;

	size = ft_strl(s1) + ft_strl(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	pos = 0;
	while (s1[i] && s1)
		new[pos++] = s1[i++];
	i = 0;
	while (s2[i] && s2)
		new[pos++] = s2[i++];
	new[pos] = '\0';
	return (new);
}

static t_list	*create_elem(char *path, struct dirent *dir)
{
	t_list			*new;
	struct stat		buf;
	struct passwd	*pw;
	struct group	*gr;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		exit(0);
	lstat(path, &buf);
	if (!(pw = getpwuid(buf.st_uid)))
		pw = getpwuid(0);
	if (!((gr = getgrgid(buf.st_gid))))
		gr = getgrgid(0);
	new->buf = buf;
	new->path = ft_strdup(path);
	new->pw = ft_strdup(pw->pw_name);
	new->gr = ft_strdup(gr->gr_name);
	new->name = ft_strdup(dir->d_name);
	new->next = NULL;
	return (new);
}

char			*ls_create_fp(char *path)
{
	int		len;

	len = (int)ft_strl(path) - 1;
	if (path[len] != '/')
		return (ft_strjoin(path, "/"));
	else
		return (ft_strdup(path));
}

void			ls_insert_elem(t_list **head, struct dirent *dr, char *path)
{
	t_list	*new;
	char	*test;

	new = *head;
	if (!new)
	{
		test = ft_strjoin(path, dr->d_name);
		new = create_elem(test, dr);
		free(test);
		*head = new;
	}
	else
	{
		while (new->next)
			new = new->next;
		test = ft_strjoin(path, dr->d_name);
		new->next = create_elem(test, dr);
		free(test);
	}
}
