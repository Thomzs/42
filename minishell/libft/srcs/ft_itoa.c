/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:57:19 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/15 13:06:55 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count(int n)
{
	int k;
	int i;

	i = n;
	k = 0;
	while (i != 0)
	{
		i /= 10;
		k++;
	}
	return (k);
}

char				*ft_itoa(int n)
{
	int		k;
	int		p;
	char	*str;

	k = (n > 0 ? 0 : 1);
	p = (n >= 0 ? 1 : 0);
	k = (n == -2147483648 ? 11 : k + count(n));
	if (!(str = (char*)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	str[k--] = '\0';
	if (n == -2147483648)
	{
		str[k--] = 8 + '0';
		n /= 10;
	}
	n = (n <= 0 ? -n : n);
	str[0] = (p == 0 ? 45 : 0);
	while ((p == 0 && k > 0) || (p == 1 && k >= 0))
	{
		str[k--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
