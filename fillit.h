/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spolowy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:54:37 by spolowy           #+#    #+#             */
/*   Updated: 2016/11/24 17:14:22 by spolowy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF 21
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_tetri
{
	int			p1[2];
	int			p2[2];
	int			p3[2];
	char		letter;
}				t_tetri;

t_tetri			*ft_global_check(char *file_name, int *pcs);
int				ft_sharp_check(char *buf, int line, int *cnts);
int				ft_grille(int nb);
int				ft_round(float nb);
int				ft_p1(char *buf, t_tetri *tetri, int x_ref, int y_ref);
int				ft_p2(char *buf, t_tetri *tetri, int x_ref, int y_ref);
int				ft_p3(char *buf, t_tetri *tetri, int x_ref, int y_ref);
int				ft_norme_vector(int x, int y, int x_ref, int y_ref);
void			ft_letter_assignation(t_tetri *tetris);
void			ft_start(t_tetri *tetris, int pcs);
char			**ft_createmap(int bsq);
void			ft_display_map(char **map, int sze_sqr);
void			ft_putchar(char c);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *s);
float			ft_sqrt(int nb);
int				ft_abs(int nbr);
void			ft_putstr(char const *s);
char			**ft_strsplit(const char *s, char c);
int				ft_split_piece(char *buffer);

#endif
