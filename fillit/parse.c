/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:42:33 by maabou-h          #+#    #+#             */
/*   Updated: 2018/12/09 14:56:12 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_hex	read_block(int fd, char *buf, t_block *lst, t_hex tetrimino)
{
	int		index;
	t_hex	pow;

	tetrimino = 0;
	index = 0;
	pow = 32768;
	while (++index < 21)
	{
		if (read(fd, &(*buf), 1) < 0)
			return (0);
		if (!(index % 5))
		{
			if (*buf != '\n')
				error_msg_list(lst, fd);
		}
		else if (*buf != '.' && *buf != '#')
			error_msg_list(lst, fd);
		else
		{
			if (*buf == '#')
				tetrimino += pow;
			pow /= 2;
		}
	}
	return (tetrimino);
}

char	**shorttab(t_hex tetrimino)
{
	char	**tab;
	int		i;
	int		j;

	i = 4;
	j = 4;
	if (!(tab = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	while (--i >= 0)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * 5)))
			return (NULL);
		tab[i][4] = '\0';
		while (--j >= 0)
		{
			tab[i][j] = (tetrimino % 2 ? ('#') : '.');
			tetrimino /= 2;
		}
		j = 4;
	}
	tab[4] = 0;
	return (tab);
}

t_block	*create_list(char *file, int *index)
{
	int		fd;
	char	buf;
	ssize_t	k;
	t_block	*lst;
	t_hex	tetrimino;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_msg();
	lst = NULL;
	tetrimino = 0;
	while ((tetrimino = read_block(fd, &buf, lst, tetrimino)) != 0)
	{
		if (!(tetrimino = clear_block(tetrimino)) || *index == 26)
			error_msg_list(lst, fd);
		else
			insert_elem(&lst, tetrimino, shorttab(tetrimino), (*index)++);
		if ((k = read(fd, &buf, 1)) && buf != '\n')
			error_msg_list(lst, fd);
		if (k == 0)
			break ;
	}
	close(fd);
	return (lst);
}

int		map_size(int nblocks)
{
	int i;

	i = 0;
	if (nblocks == 1)
		return (2);
	while (i * i < (nblocks * 4))
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	t_block	*list;
	int		i;
	int		mapsize;
	char	**map;

	i = 0;
	if (ac != 2)
		usage_msg();
	if (!(list = create_list(av[1], &i)))
		error_msg();
	mapsize = map_size(list_size(list));
	if (!(map = make_map(mapsize)))
		error_all(map, list);
	while (!(solve(list, mapsize, map)))
	{
		free_map(&map);
		mapsize++;
		if (!(map = make_map(mapsize)))
			error_all(map, list);
	}
	print_map(map, mapsize);
	free_map(&map);
	list_free(&list);
	return (0);
}
