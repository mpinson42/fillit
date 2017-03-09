#include "fillit.h"

int ft_pars(t_env *e, char *file)
{
	int fd;
	char *buff;
	char **str;
	int count;
	int bol;
	int i;
	int j;
	int count_adj;
	int count_htag;
	int count_dot;
	int bol2;

	i = 0;
	j = 0;
	bol = 0;
	fd = open(file, O_RDONLY);
	if(fd == -1)
	{
		ft_putstr("open failed");
		bol = 1;
	}
	while((count = read(fd, buff, 21)) > 0)
	{
		bol2 = 0;
		count_dot = 0;
		count_adj = 0;
		count_htag = 0;
		if(count != 21 && count != 20)
			bol = 2;
		if(buff[4] != '\n' || buff[9] != '\n' || buff[14] != '\n' || buff[19] != '\n')
			bol = 3;
		str = ft_strsplit(buff, '\n');
		i = 0;
		while(str[i] != NULL)
		{
			j = 0;
			while(str[i][j] != '\0')
			{
				if(str[i][j] == '.')
					count_dot++;
				if(str[i][j] == '#')
				{
					count_htag++;
					if(bol2 == 1)
					{
						e->htag1[0] =
						e->htag1[1] =
					}
					if(bol2 == 2)
					{
						e->htag2[0] =
						e->htag2[1] =
					}
					if(bol3 == 3)
					{
						e->htag3[0] =
						e->htag3[1] =
					}
					bol2++;
				}
				if(str[i][j] == '#' && i != 0 && str[i - 1][j] == '#')
					count_adj++;
				if(str[i][j] == '#' && j != 0 && str[i][j - 1] == '#')
					count_adj++;
				if(str[i][j] == '#' && i != 3 && str[i + 1][j] == '#')
					count_adj++;
				if(str[i][j] == '#' && j != 3 && str[i][j + 1] == '#')
					count_adj++;
				j++;
			}
			i++;
		}
		if(count_adj != 8 && count_adj != 6)
			bol = 5;
		if(count_htag != 4)
			bol = 6;
		if(count_dot != 12)
			bol = 7;
		//printf("%d\n", count_htag);
		//printf("%s", buff);
	}
	printf("\n\n\n%d", bol);
	return(bol);
}