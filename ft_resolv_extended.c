/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_extended.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spolowy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:52:07 by spolowy           #+#    #+#             */
/*   Updated: 2016/11/23 18:09:15 by spolowy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_strsetnew(char c, int size)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (size--)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		**ft_createmap(int pcs)
{
	char	**map_y;
	char	*map_x;
	int		i;

	if (!(map_y = (char**)malloc((pcs + 1) * sizeof(char*))))
		return (NULL);
	i = pcs;
	map_y[i] = NULL;
	while (--i >= 0)
	{
		map_x = ft_strsetnew('.', pcs);
		map_y[i] = map_x;
	}
	return (map_y);
}

void		ft_display_map(char **map, int sze_sqr)
{
	int		cnti;
	int		cntj;

	cnti = 0;
	cntj = 0;
	if (map == NULL)
		return ;
	while (cnti < sze_sqr)
	{
		while (cntj < sze_sqr)
		{
			write(1, &(map[cnti][cntj]), 1);
			cntj++;
		}
		write(1, "\n", 1);
		cnti++;
		cntj = 0;
	}
}
