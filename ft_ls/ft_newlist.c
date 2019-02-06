#include "ft_ls.h"

int 	ft_strl(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int	i;
	int	pos;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * ft_strl(s1) + ft_strl(s2) + 1)))
		return (NULL);
	i = 0;
	pos = 0;
	while (s1[i])
		new[pos++] = s1[i++];
	i = 0;
	while (s2[i])
		new[pos++] = s2[i++];
	new[pos] = '\0';
	return (new);
}

static t_list 	*create_elem(char *path, struct dirent *dir)
{
	t_list *new;
	struct stat buf;
	struct passwd *pw;
	struct group *gr;

	if (!(new = malloc(sizeof(t_list))))
		exit(0);
	if (lstat(path,&buf) == -1)
		exit(0);
	if (!(pw = getpwuid(buf.st_uid)))
		exit(0);
	if (!((gr = getgrgid(buf.st_gid))))
		exit(0);
	new->buf = buf;
	new->path = ft_strjoin("", path);
	new->pw = pw->pw_name;
	new->gr = gr->gr_name;
	new->name = ft_strjoin("", dir->d_name);
	new->next = NULL;
	return (new);
}

char *ls_create_fp(char *path)
{
	char *new;

	if (path[ft_strl(path) - 2] != '/')
	{
		new = ft_strjoin(path, "/");
		return (new);
	}
	return (path);
}

void 	ls_insert_elem(t_list **head, struct dirent *dirdir, char *path)
{
	t_list *new;

	new = *head;
	if (!new)
	{
		new = create_elem(ft_strjoin(path, dirdir->d_name), dirdir);
		*head = new;
	}
	else
	{
		while (new->next)
			new = new->next;
		new->next = create_elem(ft_strjoin(path, dirdir->d_name), dirdir);
	}
}
