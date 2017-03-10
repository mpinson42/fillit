#include "fillit.h"

int ft_copy_lst(t_env *e, t_resolv *r)
{
	t_resolv *tmp;
	t_resolv *tmp2;
	int i;
	
	i = 65;
	tmp2 = r;
	while(e)
	{
		tmp = r;
		r->htag1[0] = e->htag1[0];
		r->htag1[1] = e->htag1[1];
		r->htag2[0] = e->htag2[0];
		r->htag2[1] = e->htag2[1];
		r->htag3[0] = e->htag3[0];
		r->htag3[1] = e->htag3[1];
		r->type = i;
		e = e->next;
		
		r->next = (t_resolv *)malloc(sizeof(t_resolv));
		r = r->next;
		r->presed = tmp;
		i++;
	}

	r = tmp2;
	return(i - 64);
}

int ft_sqrt(int i)
{

}

char **ft_creatmap(int i)
{
	
}

void ft_resolve(t_env *e)
{
	t_resolv r;
	int i;

	r->map = ft_creatmap(ft_sqrt(ft_copy_lst(e, &r)));
	printf("htag 1 = x : %d ------ y : %d\n", r.next->next->htag1[0], r.next->next->htag1[1]);
	printf("htag 2 = x : %d ------ y : %d\n", r.next->next->htag2[0], r.next->next->htag2[1]);
	printf("htag 3 = x : %d ------ y : %d\n", r.next->next->htag3[0], r.next->next->htag3[1]);
	printf("type : %c\n", r.next->next->type);
}