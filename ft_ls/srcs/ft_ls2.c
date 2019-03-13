/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <tmeyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 23:52:52 by tmeyer            #+#    #+#             */
/*   Updated: 2019/02/19 10:24:29 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print(t_list *head, char flag, t_param *p)
{
	t_list *tmp;

	tmp = head;
	while (tmp)
	{
		if (flag & F_L)
			ft_printperm(tmp, flag, p);
		else
			ft_printpermtwo(tmp, p->path, flag);
		tmp = tmp->next;
	}
}

static void		ft_flags(char flag, t_list **head)
{
	if ((*head)->next == NULL)
		return ;
	if (*head)
		ascii_list(head);
	if (*head && (flag & F_T))
		sort_list(head);
	if (*head && (flag & F_RL))
		rev_list(head);
}

static void		ft_recursive(t_list *head, char flag, t_pos t)
{
	t_list *tmp;

	tmp = head;
	if (recursive(&tmp, flag, t) == 0)
		ft_printf("ft_ls: next directory causes a cycle\n");
}

int				ft_ls_two(t_list *arg, char flag, t_param *p, t_pos t)
{
	if (t.x && !t.y && p->type == 'd')
	{
		ft_printf("%s:\n", p->path);
		t.y++;
	}
	if (arg)
		ft_flags(flag, &arg);
	if (arg && arg->next != NULL && (flag & F_L) && is_dir(p->path))
		ft_printf("total %lld\n", ft_getblk(arg));
	ft_print(arg, flag, p);
	if ((flag & F_RU) && arg)
		ft_recursive(arg, flag, t);
	if (arg)
		ft_lstdel(&arg);
	return (1);
}
