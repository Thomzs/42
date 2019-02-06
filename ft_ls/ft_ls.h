
#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
/* opendir, readdir, closedir, readlink, strerror
**/
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
/* getpwuid, getgrgid, stat
**/
# include <time.h>
/* time, ctime
**/
# include <wchar.h>
# include <string.h>
/* wide char
**/
# include <grp.h>
# include <pwd.h>
/* listxattr, getgrgid, getpwuid, getxattr
**/
# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>

# define F_RU 1
# define F_RL 2
# define F_A 4
# define F_L 8
# define F_T 16
# define PATHS 32
# define ISFLAG 64
# define DIRSIZE 1024

typedef struct  s_list
{
  struct stat   buf;
  char          *pw;
  char          *gr;
  char          *name;
  char          *path;
  struct s_list *next;
}               t_list;

t_list	*ft_lstdelone(t_list *target);
void	ft_lstdel(t_list **alst);
void	ft_sl(int i, char *av[], char flag);
void	ft_ls(char *path, char flag);
void	illegal_opt(char *path);
void	swap(t_list *a, t_list *b);
void	ls_insert_elem(t_list **head, struct dirent *dirdir, char *path);
void	ft_printperm(t_list *arg);
char	*ft_strjoin(char *s1, char *s2);
char	*ls_create_fp(char *path);
void	recursive(t_list **arg, char flag);
void	sort_list(t_list **head);
void	rev_list(t_list **arg);
void	ascii_list(t_list **head);
int		ft_strlen(char *s);
int		ft_printf(char const *format, ...);
int		ft_strcmp(char *s1, char *s2);
int		ft_strrchr(char *s, int c);


#endif
