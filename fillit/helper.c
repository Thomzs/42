/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:41:35 by maabou-h          #+#    #+#             */
/*   Updated: 2018/12/09 11:29:58 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

void	free_map(char ***map)
{
	char	**freed;
	int		i;

	freed = *map;
	i = 0;
	while (freed[i])
		free(freed[i++]);
	free(freed);
}

char	*ft_strfill(char *str, int c, int mapsize)
{
	int i;

	i = -1;
	while (++i < mapsize)
		str[i] = (char)c;
	return (str);
}

char	**make_map(int mapsize)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * ((size_t)mapsize + 1))))
		return (NULL);
	while (i < mapsize)
	{
		if (!(map[i] = (char*)ft_memalloc((size_t)mapsize + 1)))
			return (NULL);
		ft_strfill(map[i++], '.', mapsize);
	}
	map[mapsize] = NULL;
	return (map);
}

void	print_map(char **map, int mapsize)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < mapsize)
			ft_putchar(map[i][j++]);
		i++;
		write(1, "\n", 1);
	}
}
