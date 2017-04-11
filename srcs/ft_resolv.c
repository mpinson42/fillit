#include "fillit.h"

int ft_copy_lst(t_env *e)
{
	int i;
	
	i = 65;
	while(e)
	{
		e->type = i;
		e->maps = NULL;
		e->x = 0;
		e->y = 0;
		e = e->next;
		i++;
	}
	e = NULL;
	return(i - 65);
}

int ft_sqrt(int nb)
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

char **ft_creatmap(int i)
{
	char **tab;
	int x;

	x = 0;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	while(x < i)
	{
		tab[x] = (char *)malloc(sizeof(char) * (i + 1));
		ft_memset(tab[x], '.', i);
		tab[x][i + 1] = 0;
		x++;
	}
	tab[x] = NULL;
	return(tab);
}

void ft_resolve(t_env *e)
{
	int i;

	i = 0;
	e->maps = ft_creatmap(ft_sqrt(ft_copy_lst(e) * 4));
	ft_algo(e);
/*	printf("htag 1 = x : %d ------ y : %d\n", e->next->htag1[0], e->next->htag1[1]);
	printf("htag 2 = x : %d ------ y : %d\n", e->next->htag2[0], e->next->htag2[1]);
	printf("htag 3 = x : %d ------ y : %d\n", e->next->htag3[0], e->next->htag3[1]);
	printf("type : %c\n\n\n", e->next->type);

	while(e->next->maps[i] != NULL)
	{
		//ft_putstr("lol");
		ft_putstr(e->next->maps[i]);
		ft_putchar('\n');
		i++;
	}*/
}
