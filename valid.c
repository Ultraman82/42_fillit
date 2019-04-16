/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:28:22 by chjeong           #+#    #+#             */
/*   Updated: 2019/04/16 15:28:24 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "fillit.h"

void	ft_trm_arrdel(char **trm_arr)
{
	size_t	i;

	i = 0;
	while (trm_arr[i])
	{
		free(trm_arr[i]);
		++i;
	}
	free(trm_arr);
}

t_bool	bool_strstr(const char *trm, const char *valid)
{
	int			len;

	while (*trm)
	{
		len = 0;
		while (*trm == *valid)
		{
			valid++;
			trm++;
			len++;
			if (!*valid)
				return (true);
		}
		trm = trm - len;
		valid = valid - len;
		trm++;
	}
	return (false);
}
//Creating array of valid tetrominoes
void	populate_valid(int i, char valid[20][15])
{
	while (++i < 20)
	{
		ft_bzero(valid[i], sizeof(valid[i]));
	}
	ft_strcpy(valid[0], "###...#");
	ft_strcpy(valid[1], ".#...#..##");
	ft_strcpy(valid[2], "#...###");
	ft_strcpy(valid[3], "##..#...#");
	ft_strcpy(valid[4], "###.#");
	ft_strcpy(valid[5], "##...#...#");
	ft_strcpy(valid[6], "..#.###");
	ft_strcpy(valid[7], "#...#...##");
	ft_strcpy(valid[8], "###..#");
	ft_strcpy(valid[9], ".#..##...#");
	ft_strcpy(valid[10], ".#..###");
	ft_strcpy(valid[11], "#...##..#");
	ft_strcpy(valid[12], ".##.##");
	ft_strcpy(valid[13], "#...##...#");
	ft_strcpy(valid[14], "##..##");
	ft_strcpy(valid[15], "#...#...#...#");
	ft_strcpy(valid[16], "####");
	ft_strcpy(valid[17], ".#..##..#");
	ft_strcpy(valid[18], "##...##");
}

t_bool	valid_pattern(char **trm_arr, int n_blocks)
{
	char	valid[20][15];
	int		i;
	int		j;
	int		valid_flg;

	populate_valid(-1, valid);
	i = -1;
	while (++i < n_blocks)
	{
		valid_flg = 0;
		j = -1;
		while (++j < 19)
		{
			if (bool_strstr(trm_arr[i], valid[j]) == true)
			{
				ft_bzero(trm_arr[i], ft_strlen(trm_arr[i]));
				ft_strcpy(trm_arr[i], valid[j]);
				valid_flg = 1;
				break ;
			}
		}
		if (!valid_flg)
			return (false);
	}
	return (true);
}
