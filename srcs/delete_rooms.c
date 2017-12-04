/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:39:17 by amansour          #+#    #+#             */
/*   Updated: 2017/12/04 14:08:41 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_room(t_room **r)
{
	t_room *tmp;

	while (*r)
	{
		tmp = *r;
		*r = (*r)->next;
		free(tmp->name);
		delete_link(&(tmp->link));
		free(tmp);
	}
}

t_room		*find_room(t_env *e, char *str)
{
	t_room *r;

	r = R;
	while (r)
	{
		if (!ft_strcmp(r->name, str))
			return (r);
		r = r->next;
	}
	return (NULL);
}

int			length_room(t_room *r)
{
	int		n;
	t_room	*tmp;

	n = 0;
	tmp = r;
	while (tmp)
	{
		++n;
		tmp = tmp->next;
	}
	return (n);
}
