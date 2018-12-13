/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:21:57 by maabou-h          #+#    #+#             */
/*   Updated: 2018/12/09 14:22:00 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	char	*ns;

	ns = (char*)b;
	while (len > 0)
	{
		*ns++ = (unsigned char)c;
		len--;
	}
	return (b);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void		*ft_memalloc(size_t size)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(tmp, size + 1);
	return (tmp);
}

void		ft_putchar(char c)
{
	write(1, &c, sizeof(c));
}
