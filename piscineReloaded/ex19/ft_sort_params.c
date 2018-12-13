/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:21:15 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/08 10:54:56 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (s1[i] == '\0' ^ s2[i] == '\0')
		return (s1[i] == '\0' ? -1 : 1);
	return (s1[i] - s2[i]);
}

void	ft_print_params(int argc, char **argv)
{
	int i;

	i = 1;
	while (i <= argc - 1)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i <= argc - 2)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			argv[argc] = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = argv[argc];
			i = 0;
		}
		i++;
	}
	ft_print_params(argc, argv);
}
