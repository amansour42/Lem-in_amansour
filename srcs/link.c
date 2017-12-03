/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:39:47 by amansour          #+#    #+#             */
/*   Updated: 2017/11/30 16:43:55 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_link(t_link **tube, char *str)
{
	t_link *tmp;
	t_link *list;

	tmp = NULL;
	if ((tmp = (t_link*)malloc(sizeof(t_link))))
	{
		tmp->name = ft_strdup(str);
        tmp->pass = 0;
		tmp->next = NULL;
		if (!*tube)
			*tube = tmp;
		else
		{
			list = *tube;
			while (list->next)
				list = list->next;
			list->next = tmp;
		}
	}
	return ;
}

void		delete_link(t_link **link)
{
	t_link *tmp;

	while (*link)
	{
		tmp = *link;
		*link = (*link)->next;
		free(tmp->name);
		free(tmp);
	}
}
