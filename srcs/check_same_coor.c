/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_same_coor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:33:42 by amansour          #+#    #+#             */
/*   Updated: 2017/12/06 09:36:34 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_same_coor(t_env *e)
{
	t_room *r;
	t_room *r2;

	r = R;
	while (r->next)
	{
		r2 = r->next;
		while (r2)
		{
			if (r2->x == r->x && r2->y == r->y)
			{
				clean(e);
				ft_error();
			}
			r2 = r2->next;
		}
		r = r->next;
	}
}
