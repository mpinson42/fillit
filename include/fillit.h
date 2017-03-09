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

}				t_env;

int ft_pars(t_env *e, char *file);
#endif