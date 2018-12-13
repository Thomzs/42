/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:14:23 by maabou-h          #+#    #+#             */
/*   Updated: 2018/12/09 14:32:17 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef uint16_t	t_hex;

typedef struct		s_block
{
	char			**string;
	t_hex			tetrimino;
	int				index;
	int				width;
	int				height;
	struct s_block	*next;
}					t_block;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

void				ft_putchar(char c);
void				*ft_memalloc(size_t size);
int					solve(t_block *list, int mapsize, char **map);

int					map_size(int nblocks);
t_block				*create_list(char *file, int *index);
char				**shorttab(t_hex tetrimino);
t_hex				read_block(int fd, char *buf, t_block *lst,
					t_hex tetrimino);

void				usage_msg(void);
void				error_all(char **map, t_block *list);
void				error_msg_list(t_block *list, int fd);
void				error_msg(void);

void				list_free(t_block **list);
void				insert_elem(t_block **head, t_hex tetrimino, char **string,
					int index);
t_block				*create_elem(t_hex tetrimino, char **string, int index);
int					list_size(t_block *head);

void				print_map(char **map, int mapsize);
char				**make_map(int mapsize);
char				*ft_strfill(char *str, int c, int mapsize);
void				free_map(char ***map);

int					tetri_height(char **string);
int					tetri_width(char **string);
t_hex				clear_block(t_hex tetrimino);
int					check_block(t_hex tetrimino);

#endif
