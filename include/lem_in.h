/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:55:04 by amansour          #+#    #+#             */
/*   Updated: 2017/12/05 15:54:20 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../libprint/includes/ft_printf.h"
# include <stdlib.h>

# define A				e->a_nbr
# define R				e->r
# define RNBR			e->r_nbr
# define ANTHILL		e->f
# define END			e->end
# define START			e->start
# define PATH			e->path
# define LINK			e->path->link
# define INVPATH		e->invpath
# define INVLINK		e->invpath->LINK
# define ANTNBR			"ANTS' NUMBER ERROR!\n"
# define INVALIDMAP		"INVALID MAP\n"
# define NOSTART		"NO COMMAND START\n"
# define NOEND			"NO COMMAND END\n"
# define WRONGROOM		"WRONG ROMM'S FORMAT\n"
# define INVALIDLINK	"INVALID LINK\n"
# define NOLINKS		"NOLINKS\n"

typedef struct		s_file
{
	char			*str;
	struct s_file	*next;
}					t_file;

typedef struct		s_link
{
	char			*name;
	int				pass;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	t_link			*link;
	int				len;
	struct s_path	*next;
}					t_path;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
	t_link			*link;
}					t_room;

typedef struct		s_env
{
	t_room			*r;
	t_file			*f;
	int				r_nbr;
	int				a_nbr;
	char			*start;
	char			*end;
	t_path			*path;
	t_path			*invpath;
	int				flag;
	int				long_path;
	int				color;
	int				display;
	int				no_map;
	int				no_move;
}					t_env;

int					main(int ac, char **av);
void				clean(t_env *e);
/*
** checking
*/

void				check_nbr_ants(t_env *e);
char				*check_room(t_env *e);
int					check_end(t_env *e, char *line);
void				check_map(t_env *e, char *line);
void				check_link(t_env *e, char *str);
void				clean_split(char **str);
int					length(char **str);

/*
** error
*/

int					ft_error(char *str);
void				ft_usage(void);
void				ft_error_format(void);
/*
** room
*/

void				fill_room(t_env *e, char *str, int end);
void				delete_room(t_room **r);
t_room				*find_room(t_env *e, char *line);
int					length_room(t_room *r);
/*
** map
*/

void				init_map(t_env *env);

/*
** extra
*/
void				print_move(t_env *e);
void				print_ants(t_env *e);

/*
** comment
*/

void				add_to_file(t_env *e, char *line);
int					ft_iscomment(char *line);
void				delete_first_file(t_file **f);
void				delete_file(t_file **f);

/*
** link
*/

void				delete_link(t_link **link);
void				add_link(t_link **link, char *str);

/*
** PATH
*/

void				find_path(t_env *e);
void				add_path(t_path **p, t_link *l);
int					length_path(t_link *l);
void				delete_path(t_path **path);
/*
** flags
*/
void				check_flags(t_env *e, char **av, int ac);
#endif
