/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:39:35 by amansour          #+#    #+#             */
/*   Updated: 2017/12/06 09:49:03 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_error(void)
{
	ft_putstr(ERROR);
	exit(0);
	return (1);
}

void	ft_error_format(void)
{
	ft_printf("options:\n\t-h --help : to read the manual");
	ft_printf("\n\t-q --quiet_map : to hide map");
	ft_printf("\n\t-Q --quiet_moves : to hide ants\' moves");
	ft_printf("\n\t-c --colors : to display others/end in green/blue");
	ft_printf("\n\t-d --selected_paths : to display selected paths");
	exit(0);
}

void	ft_usage(void)
{
	ft_printf("Usage: ./lem-in < [map]\n\t\toptions:");
	ft_printf("\n\t\t-h --help : to read the manual\n");
	exit(0);
}
