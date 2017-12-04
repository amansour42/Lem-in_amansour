/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:40:49 by amansour          #+#    #+#             */
/*   Updated: 2017/12/04 10:35:29 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		length_path(t_link *link)
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

void	add_path(t_path **path, t_link *l)
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

void	delete_path(t_path **path)
{
	t_path *p;

	while (*path)
	{
		p = *path;
		*path = (*path)->next;
		delete_link(&(p->link));
		free(p);
	}
}
