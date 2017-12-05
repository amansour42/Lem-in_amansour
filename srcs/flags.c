/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:20:12 by amansour          #+#    #+#             */
/*   Updated: 2017/12/05 10:12:10 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	flags(t_env *e, char *str)
{
	++str;
	while (*str)
	{
		if (*str == 'h')
			ft_error_format();
		else if (*str == 'c')
			e->color = 1;
		else if (*str == 'q')
			e->no_move = 1;
		else if (*str == 'Q')
			e->no_map = 1;
		else if (*str == 'd')
			e->display = 1;
		else
			ft_usage();
		++str;
	}
}

void	check_flags(t_env *e, char **av, int ac)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
			flags(e, av[i]);
		else
			ft_usage();
	}
}
