/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c 	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 08:54:32 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/08 10:08:17 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_dc(int i, char **tab, char flag, char *envp[])
{
	char 		*str;
	int			k;
	struct stat sb;

	str = NULL;
	str = ft_strjoin(tab[i], tab[i + 1]);
	k = lstat(str, &sb);
	if (sb == NULL || ((sb.st_mode & S_IFMT) != S_IFDIR))
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (k < 0)
	{
		ft_pustr_fd("cd: permission denied: ", 2);
		ft_putendl_fd(str, 2);
	}
	else
		// RATATAC, JE TE CHOISIS ! ATTAQUE GRIFFE !
	free(str);
}

static int		check_flags(char **tab, char *from, char *to)
{
	int i;

	i = 0;
	while (from[i])
	{
		if (from[i] == 'P')
			*to |= 1;
		else if (from[i] == 'G')
			*to |= 2;
		else
		{
			ft_putstr_fd("cd: string not in pwd: -", d);
			ft_putendl_fd(&f[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

void			ft_cd(char **tab, char *envp[])
{
	int		i;
	char	flag;

	i = 1;
	flag = '\0';
	while (tab && tab[i])
	{
		if (ft_strcmp(tab[i], "--") == 0)
		{
			i++;
			break ;
		}
		if (tab[i][0] == '-' && tab[i][1] != 0
				&& !check_flags(tab, tab[i] + 1, &flag))
				return ;
		else
			break ;
		i++;
	}
	if (tab[i + 3])
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return;
	}
	ft_dc(i, tab, flag, envp);
}
