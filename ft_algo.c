/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:31:53 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/17 14:19:44 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**ft_copy_maps(char **maps)
{
	int		i;
	char	**next;

	i = 0;
	if (!(next = (char **)malloc(sizeof(char *) *
					(ft_strlen_tab(maps) + 1))))
		return (NULL);
	while (maps[i] != NULL)
	{
		if (!(next[i] = (char *)malloc(sizeof(char) *
						(ft_strlen(maps[0]) + 1))))
			return (NULL);
		ft_memcpy(next[i], maps[i], ft_strlen(maps[i]));
		i++;
	}
	return (next);
}

int		print_fin(int x, int y, t_env *e)
{
	int i;

	i = 0;
	e->maps[x][y] = e->type;
	e->maps[x + e->htag1[0]][y + e->htag1[1]] = e->type;
	e->maps[x + e->htag2[0]][y + e->htag2[1]] = e->type;
	e->maps[x + e->htag3[0]][y + e->htag3[1]] = e->type;
	while (e->maps[i] != NULL)
	{
		ft_putstr(e->maps[i]);
		ft_putchar('\n');
		i++;
	}
	return (2);
}

int		ft_check_place(t_env *e)
{
	int x;
	int y;
	int bol;

	bol = 1;
	x = e->x - 1;
	y = e->y - 1;
	while (e->maps[++x] != NULL)
	{
		y = -1;
		if (bol == 1)
			y = e->y - 1;
		bol = 0;
		while (e->maps[x][++y])
		{
			if (is_place(e, x, y) == 1)
				return (place_piece(e, x, y));
		}
	}
	if (e->presed == NULL)
		return (3);
	e->x = 0;
	e->y = 0;
	return (0);
}

void	ft_algo(t_env *e)
{
	int i;
	int size;

	size = 1;
	while (e)
	{
		i = ft_check_place(e);
		if (i == 1)
		{
			if (e->y == (int)ft_strlen(e->maps[0]))
				e->y = 0;
			if (e->y == (int)ft_strlen(e->maps[0]))
				e->x++;
			else
				e->y++;
			e = e->next;
		}
		if (i == 0)
			e = e->presed;
		i == 3 ? e->maps = ft_creatmap(ft_sqrt(ft_copy_lst(e) * 4) + size) : 0;
		i == 3 ? size++ : 0;
		if (i == 2 || e->maps == NULL)
			return ;
	}
}
