#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_env
{
	char **maps;
	int htag1[2];
	int htag2[2];
	int htag3[2];
	int x;
	int y;
	struct s_env *next;
	struct s_env *presed;
	int type;

}				t_env;

typedef struct s_resolv
{
	char **maps;
	int type;
	int htag1[2];
	int htag2[2];
	int htag3[2];
	struct s_resolv *next;
	struct s_resolv *presed;
}				t_resolv;

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
	t_env *tmp3;
}				 t_pars;

void ft_resolve(t_env *e);
int ft_pars(t_env *e, char *file);
void ft_algo(t_env *e);
int ft_copy_lst(t_env *e);
int ft_sqrt(int nb);
char **ft_creatmap(int i);

#endif
