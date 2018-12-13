/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:30:04 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/08 13:03:30 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		openit(char *file)
{
	int		fd;
	int		i;
	char	c;

	i = 0;
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	while ((i = read(fd, &c, 1)) > 0)
		write(1, &c, 1);
	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc == 2)
		openit(argv[1]);
	return (0);
}
