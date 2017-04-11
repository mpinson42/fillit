#include "fillit.h"

void ft_htag(int bol2, int i, int j, t_env *e)
{
	int x;
	int y;
	if(bol2 == 0)
	{
		x = j;
		y = i;
	}
	if(bol2 == 1)
	{
		
		e->htag1[1] = j - x;
		e->htag1[0] = i - y;
	}
	if(bol2 == 2)
	{
		e->htag2[1] = j - x;
		e->htag2[0] = i - y;
	}
	if(bol2 == 3)
	{
		e->htag3[1] = j - x;
		e->htag3[0] = i - y;
	}	
}

void ft_adj(t_env *e, t_pars *p)
{
	while(p->str[p->i] != NULL)
	{
		p->j = 0;
		while(p->str[p->i][p->j] != '\0')
		{
			if(p->str[p->i][p->j] == '#')
			{
				p->count_htag++;
				ft_htag(p->bol2, p->i + 1, p->j + 1, e);
				p->bol2++;
			}
			if(p->str[p->i][p->j] == '.')
				p->count_dot++;
			if(p->str[p->i][p->j] == '#' && p->i != 0 && p->str[p->i - 1][p->j] == '#')
				p->count_adj++;
			if(p->str[p->i][p->j] == '#' && p->j != 0 && p->str[p->i][p->j - 1] == '#')
				p->count_adj++;
			if(p->str[p->i][p->j] == '#' && p->i != 3 && p->str[p->i + 1][p->j] == '#')
				p->count_adj++;
			if(p->str[p->i][p->j] == '#' && p->j != 3 && p->str[p->i][p->j + 1] == '#')
				p->count_adj++;
			p->j++;
		}
		p->i++;
	}
}

void ft_suit(t_pars *p, t_env *e, char *buff)
{
	p->bol2 = 0;
	p->count_dot = 0;
	p->count_adj = 0;
	p->count_htag = 0;
	if(p->count != 21 && p->count != 20)
		p->bol = 2;
	if(buff[4] != '\n' || buff[9] != '\n' || buff[14] != '\n' || buff[19] != '\n')
		p->bol = 3;
	p->str = ft_strsplit(buff, '\n');
	p->i = 0;
	if(p->bol3 == 1)
	{
		p->tmp2 = e;
		if(!(e->next = (t_env *)malloc(sizeof(t_env))))
			p->bol = 42;
		e = e->next;
		e->presed = p->tmp2;
		e->next = NULL;
	}
	p->bol3 = 1;
	ft_adj(e, p);
	if(p->count_adj != 8 && p->count_adj != 6)
		p->bol = 5;
	if(p->count_htag != 4)
		p->bol = 6;
	if(p->count_dot != 12)
		p->bol = 7;
}

int ft_pars(t_env *e, char *file)
{
	int fd; 
	char buff[22];
	t_pars p;

	p.bol3 = 0;
	p.bol = 0;
	p.tmp = e;
	fd = open(file, O_RDONLY);
	if(fd == -1)
	{
		ft_putstr("open failed");
		p.bol = 1;
	}
	while((p.count = read(fd, buff, 21)) > 0)
	{
		ft_suit(&p, e , buff);
		if (e->next)
			e = e->next;
	}
	e = p.tmp;
	return(p.bol);
}
