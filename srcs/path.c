/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:14:44 by amansour          #+#    #+#             */
/*   Updated: 2017/12/04 11:59:49 by amansour         ###   ########.fr       */
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
	t_link *tmp;

	tmp = find_room(e, link->name)->link;
	while (tmp && (tmp->pass || !ft_strcmp(tmp->name, START)))
		tmp = (tmp)->next;
	return (tmp);
}

static t_link	*ft_path(t_env *e, t_link **link)
{
	t_link	*l;
	t_link	*tmp;
	t_link	*ptmp;

	l = NULL;
	if (!(tmp = right_room(e, *link)))
	{
		(*link)->pass = 1;
		return (NULL);
	}
	add_link(&l, (*link)->name);
	add_link(&l, tmp->name);
	while (tmp && tmp->name && ft_strcmp(tmp->name, END))
	{
		ptmp = tmp;
		tmp = find_room(e, tmp->name)->link;
		while (tmp && (tmp->pass || exist_already(l, tmp->name)
					|| !ft_strcmp(tmp->name, START)))
			tmp = tmp->next;
		(tmp) ? add_link(&l, tmp->name) : 0;
	}
	(tmp && ft_strcmp(tmp->name, END)) ? tmp->pass = 1 : 0;
	(!tmp || !ft_strcmp(tmp->name, END)) ? reinitialisation(e, ptmp) : 0;
	(!tmp || !ft_strcmp(tmp->name, END)) ? ptmp->pass = 1 : 0;
	return (l);
}

void			find_path(t_env *e)
{
	t_link	*l;
	t_link	*tmp;

	l = NULL;
	tmp = find_room(e, START)->link;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, END))
		{
			add_link(&l, END);
			add_path(&PATH, l);
			tmp = tmp->next;
		}
		while (tmp && !(tmp->pass))
		{
			l = ft_path(e, &tmp);
			(exist_already(l, END)) ? add_path(&PATH, l) : delete_link(&l);
		}
		(tmp) ? reinitialisation(e, tmp) : 0;
		(tmp) ? tmp = tmp->next : 0;
	}
}
