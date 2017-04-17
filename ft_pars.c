/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:32:03 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/17 18:54:20 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_adj(t_env *e, t_pars *p)
{
	while (p->str[p->i] != NULL)
	{
		p->j = -1;
		while (p->str[p->i][++p->j] != '\0')
		{
			if (p->str[p->i][p->j] == '#')
			{
				p->count_htag++;
				ft_htag(p->bol2, p->i + 1, p->j + 1, e);
				p->bol2++;
			}
			p->str[p->i][p->j] == '.' ? p->count_dot++ : 0;
			p->str[p->i][p->j] == '#' && p->i != 0 &&
				p->str[p->i - 1][p->j] == '#' ? p->count_adj++ : 0;
			p->str[p->i][p->j] == '#' && p->j != 0 &&
				p->str[p->i][p->j - 1] == '#' ? p->count_adj++ : 0;
			if (p->str[p->i][p->j] == '#' && p->i != 3 &&
					p->str[p->i + 1][p->j] == '#')
				p->count_adj++;
			if (p->str[p->i][p->j] == '#' && p->j != 3 &&
					p->str[p->i][p->j + 1] == '#')
				p->count_adj++;
		}
		p->i++;
	}
}

void	check_read(char *buff, t_pars *p)
{
	p->bol2 = 0;
	p->count_dot = 0;
	p->count_adj = 0;
	p->count_htag = 0;
	if (p->count != 21 && p->count != 20)
		p->bol = 2;
	if (buff[4] != '\n' || buff[9] != '\n' ||
			buff[14] != '\n' || buff[19] != '\n')
		p->bol = 3;
}

void	ft_suit(t_pars *p, t_env *e, char *buff)
{
	check_read(buff, p);
	p->str = ft_strsplit(buff, '\n');
	if (ft_strlen_tab(p->str) != 5 ||
			(p->str[4][0] == '#' && p->str[4][0] == '.')
			|| (p->str[0][0] == '#' && p->str[0][0] == '.'))
	{
		p->bol = 42;
		return ;
	}
	p->i = 0;
	if (p->bol3 == 1)
	{
		p->tmp2 = e;
		if (!(e->next = (t_env *)malloc(sizeof(t_env))))
			p->bol = 42;
		e = e->next;
		e->presed = p->tmp2;
		e->next = NULL;
	}
	p->bol3 = 1;
	ft_adj(e, p);
	p->count_adj != 8 && p->count_adj != 6 ? p->bol = 5 : 0;
	p->count_htag != 4 ? p->bol = 6 : 0;
	p->count_dot != 12 ? p->bol = 7 : 0;
}

int		check_file(char *buff, int fd, char *file)
{
	char test[4001];

	ft_bzero(test, 4001);
	if (buff[0] == 'l' || buff[21] == '\n')
		return (42);
	close(fd);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (42);
	read(fd, test, 4000);
	if (test[ft_strlen(test) - 2] == '\n' &&
			test[ft_strlen(test) - 1] == '\n')
		return (42);
	return (0);
}

int		ft_pars(t_env *e, char *file)
{
	int		fd;
	char	buff[22];
	t_pars	p;

	p.bol3 = 0;
	p.bol = 0;
	p.tmp = e;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (42);
	buff[0] = 'l';
	while ((p.count = read(fd, buff, 21)) > 0)
	{
		if (ft_strlen(buff) < 21 || buff[0] == 0 ||
			buff[20] == '#' || buff[20] == '.' ||
			(buff[0] != '.' && buff[0] != '#'))
			return (42);
		ft_suit(&p, e, buff);
		if (e->next)
			e = e->next;
	}
	if (check_file(buff, fd, file) == 42)
		return (42);
	return (p.bol);
}
