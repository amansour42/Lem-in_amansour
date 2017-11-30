/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:39:17 by amansour          #+#    #+#             */
/*   Updated: 2017/11/30 17:02:37 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_room(t_room **r)
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
