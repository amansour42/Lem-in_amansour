/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:03:20 by amansour          #+#    #+#             */
/*   Updated: 2017/12/01 16:12:18 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link	*ft_path(t_env *e, t_link *link)
{
	t_link	*l;
	t_room	*r;
	char	*s;
	char	*s2;

	l = NULL;
	r = find_room(e, link->name);
	add_link(&l, END);
	add_link(&l, link->name);
	s2 = link->name;
	if (!ft_strcmp(r->link->name, END))
		s = (r->link->next) ? r->link->next->name : NULL;
	else
		s = r->link->name;
	while (s && ft_strcmp(s, START))
	{
		add_link(&l, s);
		r = find_room(e, s);
		if (!ft_strcmp(r->link->name, s2) || !ft_strcmp(r->link->name, END))
			s = (r->link->next) ? r->link->next->name : NULL;
		else
			s = r->link->name;
		s2 = r->name;
	}
	(!ft_strcmp(s, START)) ? add_link(&l, s) : 0;
	return (l);
}

static int		find_start(t_link *link, char *start)
{
	t_link *tmp;

	tmp = link;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, start))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int		length_path(t_link *link)
{
	t_link	*l;
	int		i;

	i = 0;
	l = link;
	while (l)
	{
		++i;
		l = l->next;
	}
	return (i);
}

static void		add_path(t_path **path, t_link *l)
{
	t_path	*p;
	t_path	*tmp;

	if (!(p = (t_path*)malloc(sizeof(t_path))))
		return ;
	p->link = l;
	p->len = length_path(l);
	p->next = NULL;
	if (!*path)
	{
		*path = p;
		return ;
	}
	tmp = *path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = p;
}

void			find_inverse_path(t_env *e)
{
	t_room	*r;
	t_link	*l;
	t_link	*tmp;

	INVPATH = NULL;
	r = find_room(e, END);
	tmp = r->link;
	while (tmp)
	{
		l = ft_path(e, tmp);
		if (find_start(l, START))
			add_path(&INVPATH, l);
		else
			delete_link(&l);
		tmp = tmp->next;
	}
}
