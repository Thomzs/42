/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:13:46 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/15 13:14:53 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_max(int n)
{
	ft_putchar('2');
	n = n % 1000000000;
	return (n);
}

void		ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
			n = ft_max(n);
		n = -n;
	}
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
