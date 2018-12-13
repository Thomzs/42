/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:21:36 by maabou-h          #+#    #+#             */
/*   Updated: 2018/12/09 11:40:34 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void	error_msg(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	error_msg_list(t_block *list, int fd)
{
	write(1, "error\n", 6);
	if (list)
		list_free(&list);
	close(fd);
	exit(0);
}

void	error_all(char **map, t_block *list)
{
	write(1, "error\n", 6);
	if (map)
		free_map(&map);
	if (list)
		list_free(&list);
	exit(0);
}

void	usage_msg(void)
{
	write(1, "usage: ./fillit source_file\n", 29);
	exit(0);
}
