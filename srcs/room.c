/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:46:57 by amansour          #+#    #+#             */
/*   Updated: 2017/11/30 16:23:39 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	add_room(t_env *e, int x, int y, char *str)
{
	t_room *tmp;
	t_room *list;

	tmp = NULL;
	if ((tmp = (t_room*)malloc(sizeof(t_room))))
	{
		tmp->x = x;
		tmp->y = y;
		tmp->name = ft_strdup(str);
		tmp->next = NULL;
		tmp->link = NULL;
		if (!R)
			R = tmp;
		else
		{
			list = R;
			while (list->next)
				list = list->next;
			list->next = tmp;
		}
	}
	return ;
}

int			length(char **str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void		clean_split(char **s)
{
	int		nbr;

	nbr = length(s);
	free(s[0]);
	free(s[1]);
	free(s[2]);
	free(s);
}

static void		treat_error(t_env *e, char **s)
{
	delete_room(&R);
	delete_file(&ANTHILL);
	clean_split(s);
	ft_error(WRONGROOM);
}

void		fill_room(t_env *e, char *str, int flag)
{
	char	**s;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if ((flag & 2 && START) || (flag & 4 && END))
	{
		delete_room(&R);
		ft_error(INVALIDMAP);
	}
	s = ft_strsplit(str, ' ');
	if ((((x = ft_atoi(s[1])) == -1) && ft_strcmp(s[1], "-1"))
		|| (((y = ft_atoi(s[2])) == -1) && ft_strcmp(s[2], "-1")))
		treat_error(e, s);
	if (flag & 4)
		END = ft_strdup(s[0]);
	if (flag & 2)
		START = ft_strdup(s[0]);
	add_room(e, x, y, s[0]);
	clean_split(s);
	free(str);
}
