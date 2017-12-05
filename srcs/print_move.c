/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:25:20 by amansour          #+#    #+#             */
/*   Updated: 2017/12/05 11:43:22 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static char		*link_next(char *str, t_link *link)
{
	t_link *l;

	l = link;
	while (l && ft_strcmp(l->name, str))
		l = l->next;
	if (l->next)
		return (l->next->name);
	return (NULL);
}

static void		reinitialisate_position(char *str[], t_link *link, t_env *e)
{
	int i;

	i = 0;
	while (!str[i])
		++i;
	while (i < A && ft_strcmp(str[i], START))
	{
		str[i] = link_next(str[i], link);
		++i;
	}
	if (i < A)
		str[i] = link->name;
}

static int	empty(char *str[], t_env *e)
{
	int i;

	i = 0;
	while (!str[i] && i < A)
		++i;
	if (i == A)
		return (1);
	return (0);
}

void		print_move(t_env *e)
{

	int		nbr;
	char	*str[A];
	int		i;
	int		j;

	nbr = -1;
	j = (e->color) ? 5 : 0;
	while (++nbr < A)
		str[nbr] = START;
	nbr = -1;
	while (!empty(str, e))
	{
		(nbr < (A - 1)) ? ++nbr : 0;
		i = -1;
		reinitialisate_position(str, PATH->link, e);
		while (++i <= nbr)
		{
			if (str[i])
				printf("L%d-%s", i + 1, str[i]);
				(j) ? write(1, "\033[0m", 4) : 0;
			(str[i] && i < nbr) ? printf(" ") : 0;
		}
		printf("\n");
	}
}
