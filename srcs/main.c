/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:29:31 by amansour          #+#    #+#             */
/*   Updated: 2017/12/01 16:25:55 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main(void)
{
	t_env	e;
	char	*line;
    t_room  *r;
    t_link  *l;

	init_map(&e);
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
		ft_error(INVALIDMAP);
	}
	printf("START = %s, END = %s\n", e.start, e.end);
	check_link(&e, line);
	find_path(&e);
    //find_inverse_path(&e);
	//print_ants(&e);
    //r = find_room(&e, "7");
    r = e.r;
    while (r)
    {
        printf("ROOM NAME = %s ==>", r->name);
        l = r->link;
        while (l)
        {
            printf("LINK  = %s|", l->name);
            l = l->next;
         }
        printf("\n");
        r = r->next;
    }
    print_ants(&e);
	return (0);
}
