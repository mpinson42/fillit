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

char ** ft_copy_maps(char **maps)
{
	int i;
	char **next;

	i = 0;
	next = (char **)malloc(sizeof(char *) * (ft_strlen_tab(maps) + 1));
	while(maps[i] != NULL)
	{
		next[i] = (char *)malloc(sizeof(char) * (ft_strlen(maps[0]) + 1));
		ft_memcpy(next[i], maps[i], ft_strlen(maps[i]));
		i++;
	}
	return(next);
}

void print_fin(int x, int y, t_env *e)
{
	int i = 0;

	e->maps[x][y] = e->type;
	e->maps[x + e->htag1[0]][y + e->htag1[1]] = e->type;
	e->maps[x + e->htag2[0]][y + e->htag2[1]] = e->type;
	e->maps[x + e->htag3[0]][y + e->htag3[1]] = e->type;

	while(e->maps[i] != NULL)
	{
		//ft_putstr("lol");
		ft_putstr(e->maps[i]);
		ft_putchar('\n');
		i++;
	}
}

int ft_check_place(t_env *e)
{
	int x;
	int y;
	int j = 0;
	int bol;

	bol = 1;
	x = e->x;
	y = e->y;
	
	while(e->maps[x] != NULL)
	{
		y = 0;
		if(bol == 1)
			y = e->y;
		bol = 0;
		while(e->maps[x][y])
		{
			if(e->maps[x][y] == '.'  && x + e->htag1[0] >= 0 && x + e->htag1[0] < ft_strlen_tab(e->maps) && y + e->htag1[1] >= 0 && y + e->htag1[1] < (int)ft_strlen(e->maps[x]) && e->maps[x + e->htag1[0]][y + e->htag1[1]] == '.'   && x + e->htag2[0] >= 0 && x + e->htag2[0] < ft_strlen_tab(e->maps) && y + e->htag2[1] >= 0 && y + e->htag2[1] < (int)ft_strlen(e->maps[x]) && e->maps[x + e->htag2[0]][y + e->htag2[1]] == '.'  && x + e->htag3[0] >= 0 && x + e->htag3[0] < ft_strlen_tab(e->maps) && y + e->htag3[1] >= 0 && y + e->htag3[1] < (int)ft_strlen(e->maps[x]) && e->maps[x + e->htag3[0]][y + e->htag3[1]] == '.')
			{
				if(e->next == NULL)
				{
					print_fin(x, y, e);
					return(2);
				}
				e->x = x;
				e->y = y;
				e->next->maps = ft_copy_maps(e->maps);
				e->next->maps[x][y] = e->type;
				e->next->maps[x + e->htag1[0]][y + e->htag1[1]] = e->type;
				e->next->maps[x + e->htag2[0]][y + e->htag2[1]] = e->type;
				e->next->maps[x + e->htag3[0]][y + e->htag3[1]] = e->type;

			/*	j = 0;
				while(e->maps[j] != NULL)
				{
					ft_putstr(e->maps[j]);
					ft_putchar('\n');
					j++;
				}*/
		
				
				return(1);
			}
			y++;
		}
		x++;
	}
	if(e->presed == NULL)
	{

		return(3);
	}
	e->x = 0;
	e->y = 0;
	j = 0;
	return(0);
}


void ft_algo(t_env *e)
{
	int i;
	int size;

	size = 1;
	while(e)
	{
		i = ft_check_place(e);
		if(i == 1)
		{
			if(e->y == (int)ft_strlen(e->maps[0]))
			{
				e->y = 0;
				e->x++;
			}
			else
				e->y++;
			e = e->next;
		}
		else if (i == 0)
		{
			e = e->presed;
		}
		else if (i == 3)
		{
			e->maps = ft_creatmap(ft_sqrt(ft_copy_lst(e) * 4) + size);
			size++;
		}
		else if(i == 2)
			return ;
	}

}