/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:50:32 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/30 14:02:47 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int fd;	
	char *line;
	int i;
	int k;

	k = 9;
	i = 0;
	(void)ac;
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	while (1)
	{	
		if ((i = get_next_line(fd, &line)) <= 0)
		{
			if (line)
				free(line);
			close(fd);
			return (0);
		}
		else 
		{
			printf("line : \"%s\" '%d'\n", line, i);
			free(line);
		}
	}
	return (1);
}
