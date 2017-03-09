#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_env
{
	char *maps;
	int htag1[2];
	int htag2[2];
	int htag3[2];
	struct s_env *next;
	struct s_env *presed;

}				t_env;

typedef struct s_pars
{
	int fd;      //tab[0]
	char *buff;
	char **str;
	int count;   //tab[1]
	int bol;     //tab[2]
	int i;       //tab[3]
	int j;       //tab[4]
	int count_adj; //tab[5]
	int count_htag; //tab[6]
	int count_dot; //tab[7]
	int bol2;       //tab[8]
	int x;          //tab[9]
	int y;          //tab[10]
	int bol3;       // tab[11]
	t_env *tmp;
	t_env *tmp2;
}				 t_pars;

int ft_pars(t_env *e, char *file);
#endif