/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spolowy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:42:41 by spolowy           #+#    #+#             */
/*   Updated: 2016/11/24 13:39:01 by spolowy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_tetri	*tetris;
	int		pcs;
	int		cnt;

	if (ac != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	pcs = 0;
	cnt = -1;
	tetris = ft_global_check(av[1], &pcs);
	if (tetris == NULL || !pcs || pcs > 26)
		ft_putstr("error\n");
	else
	{
		ft_letter_assignation(tetris);
		ft_start(tetris, pcs);
	}
	free(tetris);
	return (0);
}
