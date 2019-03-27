/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 07:27:30 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 13:27:37 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			get_command(const int fd, char **str)
{
	int		ret;
	char	*temp;
	char	*test;
	char	buffer[BUFF_SIZE + 1];
	int		i;

	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		temp = ft_strdup(*str);
		ft_memdel((void**)str);
		*str = ft_strnjoin(temp, buffer, ret);
		ft_memdel((void**)&temp);
		if ((test = ft_strchr(*str, '\n')))
			break ;
	}
	i = ft_strlen(*str) - 1;
	str[0][i] = '\0';
	test = NULL;
	return (1);
}
