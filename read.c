/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chjeong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:28:33 by chjeong           #+#    #+#             */
/*   Updated: 2019/04/16 18:57:16 by chjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

//Just printing error message
void	error(void)
{
	ft_putstr("error\n");
}

//Validating tetronimoes by counding number of '#' and '.' which should be 4 and 16.
t_bool	valid_1(char *str, int bytes)
{
	int n;
	int i;
	int count1;
	int count2;

	n = 0;
	while (n < bytes)
	{
		i = -1;
		count1 = 0;
		count2 = 0;
		while (++i < 19)
		{
			(str[n + i] == '#') ? count1++ : 1;
			(str[n + i] == '.') ? count2++ : 1;
			if (i % 5 == 4)
				IFA((str[n + i] != '\n'), false);
		}
		IFA((count1 != 4), false);
		IFA((count2 != 12), false);
		n += 21;
	}
	return (true);
}

//Cheking letters in tetrominoes. and integrate Val1 and Val2

t_bool	valid_0(char *str, int bytes)
{
	bytes++;
	IFA((str[0] != '.' && str[0] != '#'), false);
	IFA((valid_1(str, bytes) == false), false);	
	while (*str)
	{
		IFA((!HDN(*str)), false);
		str++;
	}
	return (true);
}

int		main(int argc, char **argv)
{
	size_t	fd;
	size_t	rd;
	char	*str;
	char	**trm_arr;
	size_t	n_blocks;

	IFA1(argc != 2, ft_putstr("usage: ./fillit source_file\n"), 0);
	IFA1((str = ft_strnew(BUFFER_SIZE)) == NULL, error(), 0);
	IFA2((fd = open(argv[1], O_RDONLY, S_IRUSR)) == -1, free(str), error(), 0);
	IFA3((rd = read(fd, str, BUFFER_SIZE)) < 0, error(), free(str),
															close(fd), 0);
	close(fd);
	IFA2(str[545] != 0, error(), free(str), 0);
	IFA2(!valid_0(str, rd), error(), free(str), 0);
	n_blocks = (rd + 1) / 21;
	change_end(&str, rd);
	IFA2((trm_arr = ft_strsplit(str, 'n')) == 0, error(), free(str), 0);
	trim_newline(trm_arr);
	IFA3(!valid_pattern(trm_arr, n_blocks), error(), ft_trm_arrdel(trm_arr), free(str), 0);
	rename_block(trm_arr);
	solve(trm_arr, n_blocks);
	ft_trm_arrdel(trm_arr);
	free(str);
	return (0);
}
