/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:53:11 by amansour          #+#    #+#             */
/*   Updated: 2017/12/05 14:42:22 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_path(t_path *path, t_env *e)
{
	t_path	*p;
	t_link	*l;
	int		i;
	int		j;

	i = 0;
	p = path;
	j = (e->color) ? 5 : 0;
	while (p)
	{
		++i;
		l = p->link;
		while (l)
		{
			write(1, "\033[32m", j);
			write(1, l->name, ft_strlen(l->name));
			write(1, "\033[0m", j);
			l = l->next;
			(l) ? write(1, "\033[31m", j) : 0;
			(l) ? write(1, "--->", 4) : 0;
		}
		ft_printf("\n");
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
		ft_error("\033[31mERROR\033[0m\n");
	}
	if (!e->no_map)
		print_map(ANTHILL);
	if (e->display)
		print_path(PATH, e);
	if (!e->no_move)
		print_move(e);
	clean(e);
}
