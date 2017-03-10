#include "fillit.h"

void ft_error(int i)
{
	if(i == 1)
		ft_putstr("open or read faild");
	if(i == 2)
		ft_putstr("file bad formated");
	if(i == 3)
		ft_putstr("back slach zero bad formated");
	if(i == 5)
		ft_putstr("adj bad formated");
	if(i == 6)
		ft_putstr("# bad formated");
	if(i == 7)
		ft_putstr(". bad formated");
}

int main(int argc, char **argv)
{
	t_env e;
	int i;
	i = ft_pars(&e, argv[1]);
	if(i != 0)
	{
		ft_error(i);
		return(0);
	}
	ft_resolve(&e);
	//printf("htag 1 = x : %d ------ y : %d\n", e.next->next->htag1[0], e.next->next->htag1[1]);
	//printf("htag 2 = x : %d ------ y : %d\n", e.next->next->htag2[0], e.next->next->htag2[1]);
	//printf("htag 3 = x : %d ------ y : %d\n", e.next->next->htag3[0], e.next->next->htag3[1]);
	return(0);
}