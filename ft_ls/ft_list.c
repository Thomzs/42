/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:49:48 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/04 18:16:26 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_memdel(void **ap)
{
	if (ap)
	{
		//		free(*ap->buf);
		//		free(*ap->pw);
		//		free(*ap->gr);
		//		free(*ap->path);
		//		free(*ap->name);
		free(*ap);
		*ap = NULL;
	}
}

t_list		*ft_lstdelone(t_list *target)
{
	t_list *tmp;
	t_list *next;

	tmp = target;
	if (tmp)
	{
		next = target->next;
		ft_memdel((void**)&tmp);
		return (next);
	}
	return (NULL);
}

void	ft_lstdel(t_list **alst)
{
	if (*alst != NULL)
	{
		ft_lstdel(&((*alst)->next));
		ft_lstdelone(*alst);
	}
}
