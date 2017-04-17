/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:34:50 by mpinson           #+#    #+#             */
/*   Updated: 2017/04/13 18:34:53 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_env
{
	char			**maps;
	int				htag1[2];
	int				htag2[2];
	int				htag3[2];
	int				x;
	int				y;
	struct s_env	*next;
	struct s_env	*presed;
	int				type;
}				t_env;

typedef struct	s_resolv
{
	char			**maps;
	int				type;
	int				htag1[2];
	int				htag2[2];
	int				htag3[2];
	struct s_resolv *next;
	struct s_resolv *presed;
}				t_resolv;

typedef struct	s_pars
{
	int		fd;
	char	*buff;
	char	**str;
	int		count;
	int		bol;
	int		i;
	int		j;
	int		count_adj;
	int		count_htag;
	int		count_dot;
	int		bol2;
	int		x;
	int		y;
	int		bol3;
	t_env	*tmp;
	t_env	*tmp2;
	t_env	*tmp3;
}				t_pars;

int				is_place(t_env *e, int x, int y);
int				place_piece(t_env *e, int x, int y);
int				ft_strlen_tab(char **tab);
char			**ft_copy_maps(char **maps);
int				print_fin(int x, int y, t_env *e);
void			ft_htag(int bol2, int i, int j, t_env *e);
void			ft_resolve(t_env *e);
int				ft_pars(t_env *e, char *file);
void			ft_algo(t_env *e);
int				ft_copy_lst(t_env *e);
int				ft_sqrt(int nb);
char			**ft_creatmap(int i);

#endif
