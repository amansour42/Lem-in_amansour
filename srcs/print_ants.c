/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:53:11 by amansour          #+#    #+#             */
/*   Updated: 2017/12/06 09:46:55 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_path(t_path *path, t_env *e)
{
	t_path	*p;
	t_link	*l;
	int		i;

	i = 0;
	p = path;
	while (p)
	{
		++i;
		l = p->link;
		while (l->next)
		{
			if (e->color)
				ft_printf("\033[32m%s\033[31m-->\033[0m", l->name);
			else
				ft_printf("%s-->", l->name);
			l = l->next;
		}
		(e->color) ? ft_printf("\033[34m%s\033[0m\n", END) :
			ft_printf("%s\n", END);
		p = p->next;
	}
}

static void	print_map(t_file *file)
{
	t_file	*tmp;

	tmp = file;
	while (tmp)
	{
		ft_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void		print_ants(t_env *e)
{
	if (!PATH)
	{
		clean(e);
		ft_error();
	}
	if (!e->no_map)
		print_map(ANTHILL);
	if (e->display)
		print_path(PATH, e);
	if (!e->no_move)
		print_move(e);
	clean(e);
}
