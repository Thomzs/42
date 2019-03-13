/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:25:47 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/11 12:50:37 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
			count++;
		while (str[i] != ' ' && str[i] != '\t'
				&& str[i] != '\n' && str[i] != '\0')
			i++;
	}
	return (count);
}

static int		ft_words(char *str, int i, char **tab, int j)
{
	int	k;
	int l;
	int	n;

	l = i;
	k = 0;
	while (str[l++] > 32)
		k++;
	if (!(tab[j] = (char*)malloc(sizeof(*str) * (k + 1))))
	{
		tab = ft_freetab_char(tab);
		return (0);
	}
	l = i;
	n = 0;
	while (n < k)
		tab[j][n++] = str[l++];
	tab[j][n] = '\0';
	return (1);
}

char			**ft_split_whitespaces(char *str)
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
	while (str[i] != '\0')
	{
		while (str[i] <= 32 && str[i] != '\0')
			i++;
		if (str[i] > 32 && str[i] != '\0')
		{
			if (!ft_words(str, i, tab, j))
				return (NULL);
			j++;
		}
		while (str[i] > 32 && str[i] != '\0')
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
