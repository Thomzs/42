/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:22:17 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/19 20:54:52 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>
# include <wchar.h>
# include <string.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>

# define F_RU		1
# define F_RL		2
# define F_A		4
# define F_L		8
# define F_T		16
# define F_G		32
# define ISFLAG		64
# define DIRSIZE 	1024
# define IS_EXEC	73

# define C_RED		"\x1b[31m"
# define C_CYAN		"\x1b[36m"
# define C_MAGENTA	"\x1b[35m"
# define C_RESET	"\x1b[0m"

typedef struct		s_list
{
	struct stat		buf;
	char			*pw;
	char			*gr;
	char			*name;
	char			*path;
	struct s_list	*next;
}					t_list;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				z;
}					t_pos;

typedef struct		s_param
{
	char			*path;
	char			type;
	int				given;
	struct s_param	*next;
}					t_param;

/*
**	ft_listcreate.c
*/

size_t				ft_strl(char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ls_create_fp(char *path);
void				ls_insert_elem(t_list **head,
					struct dirent *dirdir, char *path);
/*
**	ft_listdel.c
*/

t_list				*ft_lstdelone(t_list *target);
void				ft_lstdel(t_list **alst);
void				rev_list(t_list **arg);
void				sort_list(t_list **head);
void				ascii_list(t_list **head);

/*
**	ft_listfiles.c
*/

void				ft_printpermtwo(t_list *arg, char *path, char flag);
void				ft_printperm(t_list *arg, char flag, t_param *p);

/*
**	ft_listsort.c
*/

t_param				*single_struc(char *path);
void				ascii_param(t_param **head);
t_param				*param_to_list(char *path, t_param **head);
int					recursive(t_list **arg, char flag, t_pos t);

/*
**	ft_ls.c
*/

void				special(char *path, t_list **arg);
void				ft_sl(int i, char *av[], char flag);
int					ft_ls(t_param *p, char flag, t_pos t);

/*
**	ft_ls2.c
*/

int					ft_ls_two(t_list *arg, char flag, t_param *p, t_pos t);

/*
**	ft_ls3.c
*/

void				launcher_two(DIR *d, char *flag, t_param *p, t_list **arg);
void				launcher_one(t_pos t, t_param *l1, char flag);

/*
**	ft_rwx.c
*/

void				ft_rwx_one(t_list *arg);
void				ft_rwx_two(t_list *arg);

/*
**	ft_toolbox.c
*/

int					illegal_opt(char *path);
void				illegal_flag(char op);
void				check_flags(char *from, char *to);
int					isflag(char flag);
intmax_t			ft_getblk(t_list *tmp);
int					check_path(char *path);

/*
**	ft_toolbox2.c
*/

int					is_dir(char *path);
void				swap(t_list *a, t_list *b);
size_t				ft_strrchr(char *s, int c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(char *src);

/*
**	ft_toolbox3.c
*/

char				*ft_colors(char flag, mode_t mode);
void				illegal_opt_path(char *path);
void				ft_lstdel_param(t_param **alst);

/*
**	ft_toolbox4.c
*/

void				ft_only_rights(t_list *arg);

int					ft_printf(char const *format, ...);

#endif
