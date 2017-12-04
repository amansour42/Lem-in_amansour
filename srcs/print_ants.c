/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:53:11 by amansour          #+#    #+#             */
/*   Updated: 2017/12/04 12:02:22 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_path(t_path *path)
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
		printf("LONGPATH : \033[34m%d\n", p->len);
		while (l)
		{
			printf("\033[32m%s\033[0m", l->name);
			l = l->next;
			(l) ? printf("\033[31m--->") : 0;
			(!l) ? printf("\n") : 0;
		}
		p = p->next;
	}
	printf("NBR OF PATH = \033[34m%d\n\033[0m", i);
}

void		print_ants(t_env *e)
{
	t_file	*tmp;

	tmp = ANTHILL;
	while (tmp)
	{
		printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
	print_path(PATH);
	clean(e);
}
