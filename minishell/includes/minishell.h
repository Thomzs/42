/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:30:26 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/13 14:23:13 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <stdio.h>				// TO REMOVE~

typedef struct	s_env
{
	char		**env;
	char		*PWD;
	char		*SHLVL;
	char		*prev;
}				t_env;

t_env			*free_struct(t_env *env);
t_env			*create_env(t_env *environ);
int				interpretor(char **tab, t_env *env);

int				check_str(char *str);
char			**ft_unsetenv(char *var, char **env);
char			**ft_putenv(char *var, char **env);
char			**ft_setenv(char *var, char *content, char **env);
void			ft_cd(char **tab, char *envp[]);

# endif
