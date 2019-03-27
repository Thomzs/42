/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces_m.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:25:47 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/27 13:27:26 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		count(char *str)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] <= 32 && str[i] != '\0')
			i++;
		if (str[i] > 32)
			count++;
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i++];
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		while (str[i] > 32)
			i++;
	}
	return (count);
}

static void		move(const char c, const char *str, int *l, int *k)
{
	*k += 1;
	*l += 1;
	if (str[*l] == c)
	{
		*l -= 1;
		return ;
	}
	while (str && str[*l] != c && str[*l] != '\0')
		*l += 1;
	if (str[*l] == '\0')
		*l -= 1;
}

static char		**ft_words(char *str, int *i, char **tab, int j)
{
	int k;
	int l;
	int n;

	l = *i;
	k = 0;
	while (str[l] > 32)
	{
		if (str[l] == 39 || str[l] == 34)
			move(str[l], str, &l, &k);
		l++;
	}
	n = l - k - *i;
	if (!(tab[j] = (char*)ft_memalloc(n + 1)))
		return (ft_freetab_char(tab));
	k = 0;
	while (k < n && str[*i] != '\0')
	{
		if (str[*i] != 34 && str[*i] != 39)
			tab[j][k++] = str[*i];
		*i += 1;
	}
	if (str[*i] == '\0')
		i -= 1;
	return (tab);
}

char			**ft_split_whitespaces_m(char *str)
{
	int		i;
	int		j;
	char	**tab;

	tab = NULL;
	j = count(str);
	if (!(tab = (char**)malloc(sizeof(char*) * (j + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (str && str[i] != '\0')
	{
		while (str[i] <= 32 && str[i] != '\0')
			i++;
		if (str && str[i] != '\0' && str[i] > 32)
		{
			if (!(tab = ft_words(str, &i, tab, j++)))
				return (NULL);
		}
		while (str && str[i] != '\0' && str[i] > 32)
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
