/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:32:23 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/17 18:30:17 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_htag(int bol2, int i, int j, t_env *e)
{
	int x;
	int y;

	if (bol2 == 0)
	{
		x = j;
		y = i;
	}
	if (bol2 == 1)
	{
		e->htag1[1] = j - x;
		e->htag1[0] = i - y;
	}
	if (bol2 == 2)
	{
		e->htag2[1] = j - x;
		e->htag2[0] = i - y;
	}
	if (bol2 == 3)
	{
		e->htag3[1] = j - x;
		e->htag3[0] = i - y;
	}
}

int		main(int argc, char **argv)
{
	t_env	e;
	int		i;

	if (argc != 2)
		ft_putstr("usage: fillit [file test]");
	if (argc != 2)
		return (0);
	i = ft_pars(&e, argv[1]);
	if (i != 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	i = ft_copy_lst(&e);
	if (i == -1)
		return (-1);
	if (!(e.maps = ft_creatmap(ft_sqrt(i * 4))))
		return (-1);
	ft_algo(&e);
	return (0);
}
