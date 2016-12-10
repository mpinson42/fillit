/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spolowy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:44:58 by spolowy           #+#    #+#             */
/*   Updated: 2016/11/24 18:14:51 by spolowy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_tetri	*ft_check_count(t_tetri *tetri_array, char *file_name, int pcs)
{
	char		*buf;
	int			fd;

	if ((buf = malloc(sizeof(char) * (21 * pcs) + 1)) == NULL)
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	buf[21 * pcs] = '\0';
	read(fd, buf, (21 * pcs));
	if (buf[21 * pcs - 1] == '\0')
	{
		free(buf);
		return (tetri_array);
	}
	free(buf);
	return (NULL);
}

static t_tetri	*ft_pattern_check(char *buf, t_tetri *tetri)
{
	int			cur;
	int			shrp_cnt;
	int			x_ref;
	int			y_ref;

	cur = 0;
	shrp_cnt = 0;
	if (!(ft_split_piece(buf)))
		return (NULL);
	while (buf[cur] != '#')
		cur++;
	x_ref = cur % 5;
	y_ref = cur / 5;
	if (ft_p1(buf, tetri, x_ref, y_ref))
		if (ft_p2(buf, tetri, x_ref, y_ref))
			if (ft_p3(buf, tetri, x_ref, y_ref))
				return (tetri);
	return (NULL);
}

static t_tetri	*ft_line_check(char *buf, t_tetri *tetri, int line)
{
	int			cnts[5];

	cnts[0] = 0;
	cnts[1] = 0;
	cnts[4] = 0;
	while (++line != 4)
	{
		while (buf[cnts[4]] && buf[cnts[4]] != '\n')
		{
			cnts[0] = buf[cnts[4]] == '.' ? cnts[0] + 1 : cnts[0];
			cnts[1] = buf[cnts[4]] == '#' ? cnts[1] + 1 : cnts[1];
			cnts[4]++;
		}
		cnts[4]++;
		if (ft_sharp_check(buf, line, cnts) == 0)
			return (NULL);
		cnts[0] = 0;
		cnts[3] = 5;
	}
	return (tetri);
}

static t_tetri	*ft_block_check(char *buf, t_tetri *tetri)
{
	int			i;
	int			dot_cnt;
	int			shrp_cnt;
	int			nwl_cnt;

	i = -1;
	dot_cnt = 0;
	shrp_cnt = 0;
	nwl_cnt = 0;
	while (buf[++i] && (buf[i] == '.' || buf[i] == '#' ||
				buf[i] == '\n'))
	{
		dot_cnt = buf[i] == '.' ? dot_cnt + 1 : dot_cnt;
		shrp_cnt = buf[i] == '#' ? shrp_cnt + 1 : shrp_cnt;
		nwl_cnt = buf[i] == '\n' ? nwl_cnt + 1 : nwl_cnt;
	}
	if (ft_line_check(buf, tetri, -1) == NULL)
		return (NULL);
	if (!(dot_cnt == 12 && shrp_cnt == 4 && buf[19] == '\n' && (buf[0] == '.' ||
					buf[0] == '#') && ((nwl_cnt == 5 && buf[20] == '\n') ||
						(nwl_cnt == 4 && buf[20] == '\0'))))
		return (NULL);
	else
		return (ft_pattern_check(buf, tetri));
}

t_tetri			*ft_global_check(char *file_name, int *pcs)
{
	char		*buf;
	t_tetri		*tetri_array;
	int			fd;
	int			cnt;

	if ((tetri_array = malloc(sizeof(t_tetri) * 27)) == NULL)
		return (NULL);
	cnt = -1;
	if ((buf = malloc(sizeof(char) * (BUFF + 1))) == NULL)
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	ft_memset(buf, '\0', BUFF + 1);
	while (read(fd, buf, BUFF) > 0)
	{
		if (ft_block_check(buf, &(tetri_array[++cnt])) == NULL)
			return (NULL);
		*pcs = *pcs + 1;
		ft_memset(buf, '\0', BUFF + 1);
	}
	free(buf);
	if ((close(fd)) == -1)
		return (NULL);
	tetri_array[*pcs].letter = '|';
	return (ft_check_count(tetri_array, file_name, *pcs));
}
