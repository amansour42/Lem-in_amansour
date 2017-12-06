/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:46:57 by amansour          #+#    #+#             */
/*   Updated: 2017/12/06 09:58:09 by amansour         ###   ########.fr       */
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

void		clean_split(char **s)
{
	if (s[0])
	{
		free(s[0]);
		if (s[1])
		{
			free(s[1]);
			if (s[2])
				free(s[2]);
		}
	}
	free(s);
}

static void	treat_error(t_env *e, char **s)
{
	delete_room(&R);
	delete_file(&ANTHILL);
	clean_split(s);
	ft_error();
}

static int	ft_isnumber(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && ft_isdigit(s[i]))
		++i;
	if (!s[i])
		return (1);
	return (0);
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
		ft_error();
	}
	s = ft_strsplit(str, ' ');
	if (!s[0] || !ft_isnumber(s[1]) || !ft_isnumber(s[2])
			|| (((x = ft_atoi(s[1])) == -1) && ft_strcmp(s[1], "-1"))
			|| (((y = ft_atoi(s[2])) == -1) && ft_strcmp(s[2], "-1")))
		treat_error(e, s);
	if (flag & 4)
		END = ft_strdup(s[0]);
	if (flag & 2)
		START = ft_strdup(s[0]);
	add_room(e, x, y, s[0]);
	clean_split(s);
}
