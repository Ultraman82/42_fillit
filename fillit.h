/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:03:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/16 10:39:26 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include "libft.h"


# define BUFFER_SIZE 546
# define HASHDOT(a) (a == '#' || a == '.')
# define NEWLINE(a) (a == '\n')
# define HDN(a) (a == '#' || a == '.' || a == '\n')
# define DOT(a) (a == '.')
# define DO2(a, b) {a; b;}
# define DO3(a, b, c) {a; b; c;}
# define IFA(a, b) if(a){return(b);}
# define IFA1(a, b, c) if(a){b; return(c);}
# define IFA2(a, b, c, d) if(a){b; c; return(d);}
# define IFA3(a, b, c, d, e) if(a){b; c; d; return(e);}
# define IFA4(a, b, c, d, e, f) if(a){b; c; d; e; return(f);}

typedef	enum	e_bool
{
	false,
	true
}				t_bool;
void			ft_trm_arrdel(char **trm_arr);
void			error(void);
void			change_end(char **src, int bytes);
void			trim_newline(char **src);
t_bool			valid_pattern(char **src, int blocks);
size_t			initial_board_size(size_t nb_blocks);
void			delete_map(char **map);
char			**new_map(size_t size);
void			print_map(char **map, size_t size);
t_bool			recursion(char **tbl, char **map, int col, int row);
char			get_letter(char *str);
void			rename_block(char **src);
int				solve(char **tbl, size_t blocks);
#endif
