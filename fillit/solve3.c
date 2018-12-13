/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 07:50:20 by tmeyer            #+#    #+#             */
/*   Updated: 2018/12/09 11:38:26 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

static void	remove_block(char **map, t_block *list, t_pos pos)
{
	int line;
	int col;
	int i;
	int j;

	line = pos.x;
	i = 0;
	while (i < list->height)
	{
		j = 0;
		col = pos.y;
		while (j < list->width)
		{
			if (list->string[i][j++] == '#' &&
					map[line][col] == 'A' + list->index)
				map[line][col] = '.';
			col++;
		}
		i++;
		line++;
	}
}

static void	put_block(char **map, t_block *list, t_pos pos)
{
	int line;
	int col;
	int i;
	int j;

	line = pos.x;
	i = 0;
	while (i < list->height)
	{
		j = 0;
		col = pos.y;
		while (j < list->width)
		{
			if (list->string[i][j++] == '#')
				map[line][col] = 'A' + (char)list->index;
			col++;
		}
		i++;
		line++;
	}
}

static int	placeable(char **map, t_block *list, t_pos pos, int mapsize)
{
	int line;
	int col;
	int i;
	int j;

	i = 0;
	line = pos.x;
	if ((list->width > mapsize - pos.y) || (list->height > mapsize - pos.x))
		return (0);
	while (i < list->height)
	{
		j = 0;
		col = pos.y;
		while (j < list->width)
		{
			if (list->string[i][j++] == '#' && map[line][col] != '.')
				return (0);
			col++;
		}
		i++;
		line++;
	}
	put_block(map, list, pos);
	return (1);
}

static int	resolve(int mapsize, t_block *list, char **map)
{
	int		k;
	t_pos	pos;

	pos.x = 0;
	k = -1;
	if (!list)
		return (1);
	while (pos.x < mapsize)
	{
		pos.y = 0;
		while (pos.y < mapsize)
		{
			if ((k = placeable(map, list, pos, mapsize)))
			{
				if (resolve(mapsize, list->next, map))
					return (1);
			}
			if (k == 1)
				remove_block(map, list, pos);
			pos.y++;
		}
		pos.x++;
	}
	return (0);
}

int			solve(t_block *list, int mapsize, char **map)
{
	if (!(resolve(mapsize, list, map)))
		return (0);
	return (1);
}
