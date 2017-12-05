/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:08:21 by amansour          #+#    #+#             */
/*   Updated: 2017/12/05 10:12:30 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_map(t_env *e)
{
	PATH = NULL;
	R = NULL;
	A = 0;
	RNBR = 0;
	ANTHILL = NULL;
	START = NULL;
	END = NULL;
	e->long_path = 2;
	e->display = 0;
	e->color = 0;
	e->no_map = 0;
	e->no_move = 0;
}
