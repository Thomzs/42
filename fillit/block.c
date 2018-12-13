/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:50:25 by maabou-h          #+#    #+#             */
/*   Updated: 2018/12/09 11:39:46 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		check_block(t_hex tetrimino)
{
	int	count;
	int	pos;
	int	k;

	count = 0;
	pos = -1;
	k = 0;
	while (++pos < 16)
	{
		if ((tetrimino & (1 << pos)) > 0)
		{
			count += ((tetrimino & (1 << (pos - 1))) > 0);
			count += ((tetrimino & (1 << (pos + 1))) > 0);
			count += ((tetrimino & (1 << (pos - 4))) > 0);
			count += ((tetrimino & (1 << (pos + 4))) > 0);
			k++;
		}
		if (k == 4 && (count == 6 || count == 8))
			return (1);
	}
	return (0);
}

t_hex	clear_block(t_hex tetrimino)
{
	if (!tetrimino)
		return (0);
	if (!check_block(tetrimino))
		return (0);
	while (!(tetrimino & 61440))
		tetrimino = tetrimino << 4;
	while (!(tetrimino & 34952))
		tetrimino = tetrimino << 1;
	return (tetrimino);
}

int		tetri_width(char **string)
{
	int i;
	int j;
	int width;

	i = -1;
	width = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (string[j][i] == '#')
			{
				width++;
				break ;
			}
			if (j == 3)
				return (width);
		}
	}
	return (width);
}

int		tetri_height(char **string)
{
	int i;
	int j;
	int height;

	i = -1;
	height = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (string[i][j] == '#')
			{
				height++;
				break ;
			}
			if (j == 3)
				return (height);
		}
	}
	return (height);
}
