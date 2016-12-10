/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_piece_extended.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spolowy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:45:38 by spolowy           #+#    #+#             */
/*   Updated: 2016/11/24 18:25:33 by spolowy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			ft_sharp_check(char *buf, int line, int *cnts)
{
	int		cur;
	int		shrp_cnt;
	int		dot_cnt;

	cur = 0;
	shrp_cnt = 0;
	dot_cnt = 0;
	while (buf[cur] != '\n')
	{
		shrp_cnt = buf[line * 5 + cur] == '#' ? shrp_cnt + 1 : shrp_cnt;
		dot_cnt = buf[line * 5 + cur] == '.' ? dot_cnt + 1 : dot_cnt;
		cur++;
	}
	if (shrp_cnt + dot_cnt != 4)
		return (0);
	if (line < 3 && cnts[1] > 0 && cnts[1] < 4 && !(buf[cnts[4]] == '#' ||
				buf[cnts[4] + 1] == '#' || buf[cnts[4] + 2] == '#' ||
				buf[cnts[4] + 3] == '#'))
		return (0);
	return (1);
}

int			ft_grille(int nb)
{
	int		piece;

	piece = ft_round(ft_sqrt(nb * 4));
	return (piece);
}

static int	ft_6touche(char **tab, int i, int b)
{
	int		count;

	count = 0;
	if (i + 1 <= 3 && tab[i + 1] != NULL && tab[i + 1][b] == '#')
		count++;
	if (i - 1 >= 0 && tab[i - 1][b] == '#')
		count++;
	if (b + 1 <= 3 && tab[i][b + 1] == '#')
		count++;
	if (b - 1 >= 0 && tab[i][b - 1] == '#')
		count++;
	return (count);
}

static int	check_piece(char **tab)
{
	int i;
	int j;
	int adj;

	i = 0;
	adj = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#')
				adj = adj + ft_6touche(tab, i, j);
			j++;
		}
		i++;
	}
	return (adj == 6 || adj == 8) ? 1 : 0;
}

int			ft_split_piece(char *buffer)
{
	int		i;
	int		ret;
	char	**str;

	i = 0;
	if ((str = ft_strsplit(buffer, '\n')) == NULL)
		return (0);
	ret = check_piece(str);
	return (ret);
}
