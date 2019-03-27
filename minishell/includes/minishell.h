/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:30:26 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 13:56:30 by tmeyer           ###   ########.fr       */
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
# include <dirent.h>
# include <stdio.h>				// TO REMOVE~

# define ERROR_ENV		6
# define ERROR_PARSE	2
# define ERROR_HOME		3
# define ERROR_OLDPWD	4
# define ERROR_PWD		5

# define IS_EXEC		73
# define BUFF_SIZE		1024

typedef struct	s_env
{
	char		**env;
	char		*pwd;
	char		*shlvl;
	char		*prev;
	char		*oldpwd;
	char		*home;
}				t_env;

t_env			*free_struct(t_env *env);
t_env			*create_env(t_env *environ);
int				interpretor(char **tab, t_env *env);
int				expantions(char **str, t_env *environ);
int				error_code(int code);
int				ft_cd(char **tab, t_env *environ);
int				check_line(char **line);
int				get_command(const int fd, char **str);
int				check_exec(char **tab, t_env *environ);
int				check_str(char **str, t_env *environ);
char			*get_pwd(void);
char			*ft_getenv(char *var, char **env);
char			**ft_unsetenv(char *var, char **env);
char			**ft_putenv(char *var, char **env);
char			**ft_setenv(char *var, char *content, char **env);
char			**ft_split_whitespaces_m(char *str);
void			ft_echo(char **tab);

#endif
