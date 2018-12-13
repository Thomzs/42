/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:46:21 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/15 14:59:38 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list *k;

	if (!(k = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	k->content = NULL;
	if (content == NULL)
	{
		k->content = NULL;
		k->content_size = 0;
	}
	else
	{
		if (!((k->content = ft_memalloc(content_size))))
			return (NULL);
		k->content = ft_memcpy(k->content, content, content_size);
		k->content_size = content_size;
	}
	k->next = NULL;
	return (k);
}
