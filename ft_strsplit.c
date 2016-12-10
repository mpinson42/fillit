/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spolowy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:24:57 by spolowy           #+#    #+#             */
/*   Updated: 2016/11/24 17:17:20 by spolowy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static		int		count_words(const char *s, char c)
{
	int words;
	int i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			words++;
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static		int		count_letters(const char *s, char c, int *k)
{
	int letters;

	letters = 0;
	while (s[*k] == c && s[*k])
		(*k)++;
	while (s[*k] != c && s[*k])
	{
		letters++;
		(*k)++;
	}
	return (letters);
}

static		char	**ft_sp(const char *s, char c, char **tab)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	i = 0;
	while (tab[j] != NULL)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			tab[j][k] = s[i];
			k++;
			i++;
		}
		tab[j][k] = 0;
		k = 0;
		j++;
	}
	return (tab);
}

char				**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s == NULL || (!(c)))
		return (NULL);
	j = count_words(s, c);
	i = 0;
	k = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (j + 1))))
		return (NULL);
	while (i < j)
	{
		tab[i] = (char*)malloc(sizeof(char) * (count_letters(s, c, &k)) + 1);
		i++;
	}
	tab[i] = NULL;
	return (ft_sp(s, c, tab));
}
