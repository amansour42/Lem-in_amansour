/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:34:43 by amansour          #+#    #+#             */
/*   Updated: 2017/11/30 11:34:49 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_iscomment(char *line)
{
	return (line[0] == '#' && ft_strcmp(line, "##start")
			&& ft_strcmp(line, "##end"));
}

void	add_to_file(t_env *e, char *line)
{
	t_file *c1;
	t_file *c2;

	if ((c1 = (t_file*)malloc(sizeof(t_file))))
	{
		c1->next = NULL;
		c1->str = ft_strdup(line);
		if (!ANTHILL)
			ANTHILL = c1;
		else
		{
			c2 = ANTHILL;
			while (c2->next)
				c2 = c2->next;
			c2->next = c1;
		}
	}
	return ;
}

static void	delete_first(t_file **c)
{
	t_file *tmp;

	tmp = *c;
	*c = (*c)->next;
	free(tmp->str);
	free(tmp);
}

void	delete_file(t_file **c)
{
	while (*c)
		delete_first(c);
}
