/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 08:28:36 by tmeyer            #+#    #+#             */
/*   Updated: 2019/04/03 11:40:33 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			expone_tilde(char **str, t_env *environ, int *i)
{
	if (!(*str = str_replace_str(str,
					ft_getenv("HOME", environ->env), *i, 1)))
		return (1);
	i += ft_strlen(ft_getenv("HOME", environ->env)) - 1;
	return (0);
}

int			expone_tilde_tw(char **str, t_env *environ, int *i)
{
	if (!environ->oldpwd
			|| !(*str = str_replace_str(str, environ->oldpwd + 7,
					*i + 1, 2)))
		return (1);
	*i += ft_strlen(environ->oldpwd + 7) - 1;
	return (0);
}

int			expone_tilde_tr(char **str, t_env *environ, int *i)
{
	if (!environ->pwd
			|| !(*str = str_replace_str(str, environ->pwd + 4, *i + 1, 2)))
		return (1);
	*i += ft_strlen(environ->pwd + 4) - 1;
	return (0);
}
