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

static void     reinitialisation(t_room **room)
{
    t_room  *r;
    t_link  *l;

    r = *room;
    while (r)
    {
        l = r->link;
        while (l)
        {
            l->pass = 0;
            l = l->next;
        }
        r = r->next;
    }
}

static t_link     *right_room(t_env *e, t_link *link)
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
    t_link  *ptmp;
    
    l = NULL;
    if (!(tmp = right_room(e, *link)))
    {
        (*link)->pass = 1;
        return (NULL);
    }
    add_link(&l, START);
	add_link(&l, (*link)->name);
    add_link(&l, tmp->name);
    while (tmp && tmp->name && ft_strcmp(tmp->name, END))
    {
        ptmp = tmp;
        tmp = find_room(e, tmp->name)->link;
        while (tmp && (tmp->pass || find_end(l, tmp->name) ||
                    !ft_strcmp(tmp->name, START)))
            tmp = tmp->next;
        (tmp) ? add_link(&l, tmp->name) : 0;
    }
    (tmp && ft_strcmp(tmp->name, END)) ? tmp->pass = 1 : 0;
    (!tmp || !ft_strcmp(tmp->name, END)) ? ptmp->pass = 1 : 0;
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
	t_link	*l;
	t_link	*tmp;

	PATH = NULL;
    l = NULL;
    tmp = find_room(e, START)->link;
	while (tmp)
	{
        if (!ft_strcmp(tmp->name, END))
        {
            add_link(&l, START);
            add_link(&l, END);
            add_path(&PATH, l);
            tmp = tmp->next;
        }
        while (tmp && !(tmp->pass))
        {
            l = ft_path(e, &tmp);
	    	(find_end(l, END)) ? add_path(&PATH, l) : delete_link(&l);
        }
        reinitialisation(&R);
        tmp = tmp->next;
	}
}
