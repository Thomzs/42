/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:34:47 by maabou-h          #+#    #+#             */
/*   Updated: 2018/12/09 11:17:53 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		list_size(t_block *head)
{
	char	i;

	i = 0;
	while (head)
	{
		i += 1;
		head = head->next;
	}
	return (i);
}

t_block	*create_elem(t_hex tetrimino, char **string, int index)
{
	t_block	*new;

	if (!(new = (t_block*)malloc(sizeof(t_block))))
		return (0);
	new->next = NULL;
	new->tetrimino = tetrimino;
	new->string = string;
	new->width = tetri_width(string);
	new->height = tetri_height(string);
	new->index = index;
	return (new);
}

void	insert_elem(t_block **head, t_hex tetrimino, char **string, int index)
{
	t_block *new;

	new = *head;
	if (new == NULL)
	{
		new = create_elem(tetrimino, string, index);
		*head = new;
	}
	else
	{
		while (new->next)
			new = new->next;
		new->next = create_elem(tetrimino, string, index);
	}
}

void	list_free(t_block **list)
{
	t_block *tmp;
	t_block *old;
	int		i;

	tmp = *list;
	while (tmp)
	{
		i = 0;
		while (tmp->string[i])
		{
			free(tmp->string[i]);
			i++;
		}
		free(tmp->string);
		old = tmp->next;
		free(tmp);
		tmp = old;
	}
}
