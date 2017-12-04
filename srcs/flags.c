/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:20:12 by amansour          #+#    #+#             */
/*   Updated: 2017/12/04 18:23:02 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	flags(t_env *e, char *str)
{
	while (str)
	{
		if (*str == 'h')
			e->help = 1;
		else if (*str == 'd')
			e->display = 1;
		else if (*str == 'c')
			e->color = 1;
		else if (*str == 'q')
			e->no_move = 1;
		else if (*str == 'Q')
			e->no_map = 1;
		else
			ft_usage();
		++str;
	}
}

void	check_flags(t_env *e, char **av, int ac)
{
	int i;

	i = 0;
	while (++i < ac - 1)
	{
		if (av[i][0] == '-')
			flags(e, ++av[i]);
		else
			ft_error_format();
	}
	if (av[i])
	{
		if (av[i][0] == '-' && ft_strchr(av[i], 'h'))
			ft_error_format();
		else
			ft_usage();
	}
}
