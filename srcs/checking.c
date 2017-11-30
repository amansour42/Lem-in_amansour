/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:38:59 by amansour          #+#    #+#             */
/*   Updated: 2017/11/30 16:36:36 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_nbr_ants(t_env *e)
{
	char *line;

	if (!get_next_line(0, &line))
		ft_error(INVALIDMAP);
	if ((A = ft_atoi(line)) <= 0)
		ft_error(ANTNBR);
	add_to_file(e, line);
	free(line);
}

char*		check_room(t_env *e)
{
	char	*line;
	int		flag;
	int		last_flag;

	last_flag = 0;
	while (1)
	{
		if (!get_next_line(0, &line))
		{
			delete_room(&R);
			delete_file(&ANTHILL);
			ft_error("INVALIDMAP");
		}
		if (ft_strchr(line, '-'))
			break;
		add_to_file(e, line);
		if (!ft_iscomment(line))
		{
			flag = (!ft_strcmp(line, "##start")) ? 2 : 0;
			flag = (!ft_strcmp(line, "##end")) ? 4 : flag;
			(!flag) ? fill_room(e, line, last_flag) : 0;
			last_flag = flag;
		}
		free(line);
	}
	return (line);
}

static t_room	*find_room(t_env *e, char *str)
{
	t_room *r;

	r  = R;
	while (r)
	{
		if (!ft_strcmp(r->name, str))
			return (r);
		r = r->next;
	}
	return (r);
}

void	check_link(t_env *e, char *line)
{
	t_room	*r1;
	t_room	*r2;
	char	**s;

	while (1)
	{
		add_to_file(e, line);
		if (!ft_iscomment(line))
		{
			s = ft_strsplit(line , '-');
			if (!(r1 = find_room(e, s[0])) || !(r2 = find_room(e, s[1])))
			{
				clean_split(s);
				delete_room(&R);
				delete_file(&ANTHILL);
				delete_room(&R);
				free(START);
				free(END);
				ft_error(INVALIDLINK);
			}
			add_link(&(r1->link), r2->name);
			add_link(&(r2->link), r1->name);
			clean_split(s);
		}
		free(line);
		if (!get_next_line(0, &line))
			break ;
	}
}
