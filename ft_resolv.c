/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:32:15 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/17 14:26:20 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_place(t_env *e, int x, int y)
{
	if (e->maps[x][y] == '.' && x + e->htag1[0] >= 0 &&
			x + e->htag1[0] < ft_strlen_tab(e->maps) &&
			y + e->htag1[1] >= 0 && y + e->htag1[1] <
			(int)ft_strlen(e->maps[x]) &&
			e->maps[x + e->htag1[0]][y + e->htag1[1]] == '.' &&
			x + e->htag2[0] >= 0 && x + e->htag2[0] <
			ft_strlen_tab(e->maps) && y + e->htag2[1] >= 0 &&
			y + e->htag2[1] < (int)ft_strlen(e->maps[x]) &&
			e->maps[x + e->htag2[0]][y + e->htag2[1]] == '.' &&
			x + e->htag3[0] >= 0 && x + e->htag3[0] <
			ft_strlen_tab(e->maps) && y + e->htag3[1] >= 0 &&
			y + e->htag3[1] < (int)ft_strlen(e->maps[x]) &&
			e->maps[x + e->htag3[0]][y + e->htag3[1]] == '.')
		return (1);
	return (0);
}

int		place_piece(t_env *e, int x, int y)
{
	if (e->next == NULL)
		return (print_fin(x, y, e));
	e->x = x;
	e->y = y;
	e->next->maps = ft_copy_maps(e->maps);
	e->next->maps[x][y] = e->type;
	e->next->maps[x + e->htag1[0]][y + e->htag1[1]] = e->type;
	e->next->maps[x + e->htag2[0]][y + e->htag2[1]] = e->type;
	e->next->maps[x + e->htag3[0]][y + e->htag3[1]] = e->type;
	return (1);
}

int		ft_copy_lst(t_env *e)
{
	int i;

	i = 65;
	while (e)
	{
		e->type = i;
		e->maps = NULL;
		e->x = 0;
		e->y = 0;
		e = e->next;
		i++;
	}
	if (i > 'Z')
	{
		ft_putstr("error\n");
		return (-1);
	}
	e = NULL;
	return (i - 65);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (i < 0)
		return (0);
	while (i * i < nb)
	{
		i++;
	}
	return (i);
}

char	**ft_creatmap(int i)
{
	char	**tab;
	int		x;

	x = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	while (x < i)
	{
		if (!(tab[x] = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		ft_memset(tab[x], '.', i);
		tab[x][i + 1] = 0;
		x++;
	}
	tab[x] = NULL;
	return (tab);
}
