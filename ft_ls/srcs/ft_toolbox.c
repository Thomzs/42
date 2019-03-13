/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:14:02 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/19 23:29:49 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			illegal_opt(char *path)
{
	char *str;

	if (errno == EACCES || errno == EBADF)
	{
		str = ft_strjoin("ft_ls: ", path);
		perror(str);
		free(str);
		errno = 0;
		return (0);
	}
	return (1);
}

void		illegal_flag(char op)
{
	ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls [-GRalrt] [file ...]\n"
			, op);
	exit(0);
}

void		check_flags(char *from, char *to)
{
	int i;

	i = 0;
	while (from[i])
	{
		if (from[i] == 'l')
			*to |= F_L;
		else if (from[i] == 'a')
			*to |= F_A;
		else if (from[i] == 'r')
			*to |= F_RL;
		else if (from[i] == 't')
			*to |= F_T;
		else if (from[i] == 'R')
			*to |= F_RU;
		else if (from[i] == 'G')
			*to |= F_G;
		else
			illegal_flag(from[i]);
		i++;
	}
}

int			isflag(char flag)
{
	if (flag == 'a' || flag == 'r' || flag == 'l' || flag == 't' || flag == 'R')
		return (ISFLAG);
	return (0);
}

intmax_t	ft_getblk(t_list *tmp)
{
	intmax_t	tot;

	tot = 0;
	while (tmp)
	{
		tot += tmp->buf.st_blocks;
		tmp = tmp->next;
	}
	return (tot);
}
