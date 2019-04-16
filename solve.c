/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:28:09 by chjeong           #+#    #+#             */
/*   Updated: 2019/04/16 15:28:11 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

void	remove_trm(char **map, char *trm, int col, int row)
{
	char	ch;
	int		i;

	ch = get_letter(trm);
	i = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (i == 4)
				return ;
			if (map[row][col] == ch)
			{
				i++;
				map[row][col] = '.';
			}
			col++;
		}
		row++;
	}
}

void	place(char **map, char *trm, int col, int row)
{
	size_t	i;
	int		init_col;

	init_col = col;
	i = 0;
	while (*trm == '.')
		DO3(i++, trm++, init_col--);
	while (*trm != '\0')
	{
		if (i > 3)
		{
			i = 0;
			col = init_col;
			row++;
		}
		if (*trm == '.')
			DO2(i++, col++);
		if (DOT(map[row][col]) && !DOT(*trm))
			DO3(map[row][col] = *trm, col++, i++);
		trm++;
	}
}

t_bool	is_safe(char **map, char *trm, int col, int row)
{
	size_t	i;
	int		init_col;

	init_col = col;
	i = 0;
	while (*trm == '.')
		DO3(i++, trm++, init_col--);
	CHK(init_col < 0, false);
	while (*trm != '\0')
	{
		if (i > 3)
		{
			i = 0;
			col = init_col;
			row++;
		}
		if (*trm == '.')
			DO2(i++, col++);
		CHK(!DOT(map[row][col]) && map[row][col] && !DOT(*trm), false);
		CHK(!map[row][col] && !DOT(*trm), false);
		if (DOT(map[row][col]) && !DOT(*trm))
			DO2(col++, i++);
		trm++;
	}
	return (true);
}

int		solve(char **tbl, size_t blocks)
{
	char	**map;
	size_t	map_size;

	map_size = initial_board_size(blocks);
	CHK1((map = new_map(map_size)) == 0, error(), 0);
	while (recursion(tbl, map, 0, 0) == false)
	{
		map_size++;
		delete_map(map);
		CHK1((map = new_map(map_size)) == 0, error(), 0);
	}
	print_map(map, map_size);
	delete_map(map);
	return (0);
}

t_bool	recursion(char **tbl, char **map, int col, int row)
{
	if (!*tbl)
		return (true);
	while (map[row])
	{
		while (map[row][col])
		{
			if (is_safe(map, *tbl, col, row) == true)
			{
				place(map, *tbl, col, row);
				if (recursion(tbl + 1, map, 0, 0) == true)
					return (true);
				else
					remove_trm(map, *tbl, col, row);
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (false);
}
