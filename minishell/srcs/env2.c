/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 08:22:51 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 13:21:39 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_getenv(char *var, char **env)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = ft_strjoin(var, "=");
	i = 0;
	j = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(tmp, env[i], (j = ft_strlen(tmp))))
		{
			ft_memdel((void**)&tmp);
			return (env[i] + j);
		}
		i++;
	}
	ft_memdel((void**)&tmp);
	return (NULL);
}
