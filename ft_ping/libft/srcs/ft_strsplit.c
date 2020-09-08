/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:18:30 by tmeyer            #+#    #+#             */
/*   Updated: 2019/03/07 16:10:20 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *str, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
			k++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (k);
}

static int		letters(char const *s, char c, char **tab, int i[2])
{
	int k;
	int j;
	int n;

	j = i[0];
	k = 0;
	while (s[j] != c && s[j++] != '\0')
		k++;
	if (!(tab[i[1]] = (char*)malloc(sizeof(*s) * (k + 1))))
		return (0);
	j = i[0];
	n = 0;
	while (n < k)
		tab[i[1]][n++] = s[j++];
	tab[i[1]][n] = '\0';
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i[2];
	char	**tab;

	i[0] = 0;
	i[1] = 0;
	tab = NULL;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	while (s[i[0]] != '\0')
	{
		while (s[i[0]] == c && s[i[0]] != '\0')
			i[0]++;
		if (s[i[0]] != c && s[i[0]] != '\0')
		{
			letters(s, c, tab, i);
			i[1]++;
		}
		while (s[i[0]] != c && s[i[0]] != '\0')
			i[0]++;
	}
	tab[i[1]] = NULL;
	return (tab);
}
