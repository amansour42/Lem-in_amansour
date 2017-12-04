/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:39:35 by amansour          #+#    #+#             */
/*   Updated: 2017/12/04 17:02:15 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
	return (1);
}

void	ft_error_format(void)
{
	printf("options:\n\t-h --help : to read the manual");
	printf("\n\t-q --quiet_map : to hide map");
	printf("\n\t-Q --quiet_moves : to hide ants moves");
	printf("\n\t-l --lines : to display number of move lines");
	printf("\n\t-c --colors : to display start/end in green/red");
	printf("\n\t-d --selected_paths : to display selected paths");
	printf("\n\t##follow --follow up to four rooms : colors must be enable");
	printf("\n\t##ants --name a list of ants : name1-name2-name3\n");
	exit(0);
}

void	ft_usage(void)
{
	printf("Usage: ./lem-in < [map]\n\t\toptions:");
	printf("\n\t\t-h --help : to read the manual\n");
	exit(0);
}
