/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:14:44 by amansour          #+#    #+#             */
/*   Updated: 2017/12/05 15:46:06 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		exist_already(t_link *link, char *end)
{
	t_link *tmp;

	tmp = link;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, end))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void		reinitialisation(t_env *e, t_link *link)
{
	t_link	*l;

	l = find_room(e, link->name)->link;
	while (l)
	{
		l->pass = 0;
		l = l->next;
	}
}

static t_link	*right_room(t_env *e, t_link *link)
{
	t_link	*tmp;
	t_room	*r;

	if (!(r = find_room(e, link->name)))
		return (NULL);
	tmp = r->link;
	while (tmp && (tmp->pass || !ft_strcmp(tmp->name, START)))
		tmp = (tmp)->next;
	return (tmp);
}

static void		ft_path(t_env *e, t_link **link, t_link **l)
{
	t_link	*tmp;
	t_link	*ptmp;
	int		i;

	i = 2;
	if (!(tmp = right_room(e, *link)))
	{
		(*link)->pass = 1;
		return ;
	}
	add_link(l, tmp->name);
	while (tmp && ft_strcmp(tmp->name, END) && i <= e->long_path)
	{
		ptmp = tmp;
		tmp = find_room(e, tmp->name)->link;
		while (tmp && (tmp->pass || exist_already(*l, tmp->name)
					|| !ft_strcmp(tmp->name, START)))
			tmp = tmp->next;
		(tmp) ? add_link(l, tmp->name) : 0;
		++i;
	}
	(tmp) ? tmp->pass = 1 : 0;
	(!tmp || !ft_strcmp(END, tmp->name)) ? ptmp->pass = 1 : 0;
	(!tmp || !ft_strcmp(END, tmp->name)) ? reinitialisation(e, ptmp) : 0;
}

void			find_path(t_env *e)
{
	t_link	*l;
	t_link	*tmp;

	while (!PATH && e->long_path <= length_room(R))
	{
		tmp = find_room(e, START)->link;
		while (tmp)
		{
			while (!(tmp->pass))
			{
				l = NULL;
				add_link(&l, tmp->name);
				ft_path(e, &tmp, &l);
				(exist_already(l, END)) ? add_path(&PATH, l) : delete_link(&l);
			}
			reinitialisation(e, tmp);
			tmp->pass = 0;
			tmp = tmp->next;
		}
		(!PATH) ? e->long_path += 1 : 0;
	}
}
