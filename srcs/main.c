/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:29:31 by amansour          #+#    #+#             */
/*   Updated: 2017/12/06 09:32:39 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	t_env	e;
	char	*line;

	init_map(&e);
	check_flags(&e, av, ac);
	check_nbr_ants(&e);
	line = check_room(&e);
	if (!e.end || !e.start)
	{
		free(line);
		delete_room(&(e.r));
		if (e.start)
			free(e.start);
		else if (e.end)
			free(e.end);
		ft_error();
	}
	e.r_nbr = length_room(e.r);
	check_link(&e, line);
	check_same_coor(&e);
	find_path(&e);
	print_ants(&e);
	return (0);
}
