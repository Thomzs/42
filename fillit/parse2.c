/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:42:33 by maabou-h          #+#    #+#             */
/*   Updated: 2018/12/09 10:48:39 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_hex	read_block(int fd, char *buf)
{
	int		index;
	t_hex	pow;
	t_hex	tetrimino;

	index = 0;
	pow = 32768;
	tetrimino = 0;
	while (++index < 21)
	{
		if (read(fd, &(*buf), 1) <= 0)
			return (0);
		if (!(index % 5))
		{
			if (*buf != '\n')
				error_msg();
		}
		else if (*buf != '.' && *buf != '#')
			error_msg();
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
		error_msg();
	while (--i >= 0)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * 5)))
			error_msg();
		// POSSIBLY LOST BYTES HERE
		// SI ERREUR ICI, MALLOC LIGNE 53 NON FREE
		// NI CASES ALLOUEES PRECEDEMENT DANS LA BOUCLE
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
// ATTENTION SI PLUS DE 26 TETRIMINOS
	int		fd;
	char	buf;
	t_block	*lst;
	t_hex	tetrimino;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_msg();
	lst = NULL;
	while ((tetrimino = read_block(fd, &buf)) != 0)
	{
		if (!(tetrimino = clear_block(tetrimino)))
			error_msg();
		else
		{
			insert_elem(&lst, tetrimino, shorttab(tetrimino), *index);
			*index += 1;
		}
		if (read(fd, &buf, 1) && buf != '\n')
			error_msg();
	}
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
//PENSER A close(fd) DANS TOUTES LES SORTIES D'ERREURS PLUS A LA FIN DU MAIN
//PLUS free(list) DANS TOUTES LES SORTIES D'ERREURS DES FONCTIONS CREATRICES
//DE LA LISTE
	i = 0;
	if (ac != 2)
		usage_msg();
	mapsize = 2;
	list = create_list(av[1], &i);
	mapsize = map_size(list_size(list));
	if (!(map = make_map(mapsize)))
		error_msg_(map, list);
	while (!(solve(list, mapsize, map)))
	{
		free_map(&map);
		mapsize++;
		if (!(map = make_map(mapsize)))
			error_msg_(map, list);
	}
	print_map(map, mapsize);
	free_map(&map);
	list_free(&list);
	return (0);
}
