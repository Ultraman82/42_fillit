/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:27:42 by chjeong           #+#    #+#             */
/*   Updated: 2019/04/16 15:27:45 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

# define BUFFER_SIZE 546
# define HASHDOT(a) (a == '#' || a == '.')
# define NEWLINE(a) (a == '\n')
# define HDN(a) (a == '#' || a == '.' || a == '\n')
# define DOT(a) (a == '.')
# define DO2(a, b) {a; b;}
# define DO3(a, b, c) {a; b; c;}
# define CHK(a, b) if(a){return(b);}
# define CHK1(a, b, c) if(a){b; return(c);}
# define CHK2(a, b, c, d) if(a){b; c; return(d);}
# define CHK3(a, b, c, d, e) if(a){b; c; d; return(e);}
# define CHK4(a, b, c, d, e, f) if(a){b; c; d; e; return(f);}

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
