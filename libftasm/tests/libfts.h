#ifndef LIBFTS_H
# define LIBFTS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
char	*ft_strcpy(char *dst, const char *src);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
int		ft_puts(const char *s);
void	ft_putstr(const char *s);
void	*ft_memset(void *b, int c, size_t n);
void	*ft_memcpy(void	*restrict dst, const void *restrict src, size_t n);
char	*ft_strdup(const char *src);
void	ft_cat(const int fd);

#endif 
