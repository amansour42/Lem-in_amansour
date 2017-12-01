/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:14:44 by amansour          #+#    #+#             */
/*   Updated: 2017/12/01 19:34:13 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		find_end(t_link *link, char *end)
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
static t_link	*ft_path(t_env *e, t_link *link)
{
	t_link	*l;
	t_room	*r;
	char	*s;
	t_link	*tmp;

	l = NULL;
	r = find_room(e, link->name);
	add_link(&l, START);
	add_link(&l, link->name);
	if (!ft_strcmp(r->link->name, START))
		s = (r->link->next) ? r->link->next->name : NULL;
	else
		s = r->link->name;
	while (s && ft_strcmp(s, END))
	{
		printf("OK %s\n", s);
		sleep(1);
		add_link(&l, s);
		r = find_room(e, s);
		tmp = r->link;
		s = r->link->name;
		while (s && find_end(l, s))
		{
			tmp = tmp->next;
			s = (tmp) ? tmp->name : NULL;
		}
	}
	(s && !ft_strcmp(s, END)) ? add_link(&l, s) : 0;
	return (l);
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

void			find_path(t_env *e)
{
	t_room	*r;
	t_link	*l;
	t_link	*tmp;

	PATH = NULL;
	r = find_room(e, START);
	tmp = r->link;
	while (tmp)
	{
		l = ft_path(e, tmp);
		if (find_end(l, END))
			add_path(&PATH, l);
		else
			delete_link(&l);
		tmp = tmp->next;
	}
}
