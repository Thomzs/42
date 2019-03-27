/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 08:46:56 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 13:26:39 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		echo(int i, char **tab, char flag)
{
	while (tab[i])
	{
		write(1, tab[i], ft_strlen(tab[i]));
		if (tab[i + 1] && tab[i + 1][0] != '\0')
			write(1, " ", 1);
		i++;
	}
	if (!(flag & 1))
		write(1, "\n", 1);
}

static int		check_flags(char *from, char *to)
{
	int i;

	i = 0;
	while (from[i])
	{
		if (from[i] == 'n' && (from[i + 1] == 'n' || from[i + 1] <= 32))
			*to |= 1;
		else
			return (0);
		i++;
	}
	return (1);
}

void			ft_echo(char **tab)
{
	int		i;
	char	flag;

	i = 0;
	flag = '\0';
	while (tab && tab[++i])
	{
		if (ft_strcmp(tab[i], "-") == 0)
		{
			i++;
			break ;
		}
		if (tab[i][0] == '-' && tab[i][1] != 0
				&& check_flags(tab[i] + 1, &flag))
			i++;
		else
			break ;
	}
	echo(i, tab, flag);
}
