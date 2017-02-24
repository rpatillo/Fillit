/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:50:18 by rpatillo          #+#    #+#             */
/*   Updated: 2016/04/25 15:23:27 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int			ft_createtab(t_env *e)
{
	int		i;
	int		j;

	if (!(e->split = (char ***)malloc(sizeof(char **) * (e->blocknbr + 1))))
		ft_error(2);
	i = 0;
	while (i < e->blocknbr)
	{
		if (!(e->split[i] = (char **)malloc(sizeof(char*) * 5)))
			ft_error(2);
		j = 0;
		while (j < 4)
		{
			if (!(e->split[i][j] = (char *)malloc(sizeof(char) * 5)))
				ft_error(2);
			j++;
		}
		e->split[i][j] = NULL;
		i++;
	}
	e->split[i] = NULL;
	return (0);
}

int			ft_savetab(t_env *e)
{
	e->s_k = 0;
	e->s_i = 0;
	e->s_l = 0;
	while (e->tab[e->s_i] != '\0')
	{
		if (ft_strlen(e->tab[e->s_i]) != 4)
			ft_error(1);
		if ((e->s_i % 4) == 0 && e->s_i != 0)
		{
			e->s_k++;
			e->s_l = 0;
		}
		e->s_j = 0;
		while (e->tab[e->s_i][e->s_j] != '\0')
		{
			e->split[e->s_k][e->s_l][e->s_j] = ft_savechar(e->tab[e->s_i]
				[e->s_j], e->s_k);
			e->s_j++;
		}
		e->s_l++;
		e->s_i++;
	}
	return (0);
}

char		ft_savechar(char src, int i)
{
	char	tmp;

	if (src == '#')
		tmp = 'A' + i;
	else
		tmp = src;
	return (tmp);
}

int			ft_checktetri_sub(char **tab, int i, int j)
{
	int k;

	k = 0;
	if (i - 1 >= 0 && tab[i - 1][j] != '.')
		k++;
	if (i + 1 < 4 && tab[i + 1][j] != '.')
		k++;
	if (j - 1 >= 0 && tab[i][j - 1] != '.')
		k++;
	if (j + 1 < 4 && tab[i][j + 1] != '.')
		k++;
	return (k);
}

int			ft_checktetri(char **tab)
{
	int		i;
	int		j;
	int		cnt;

	i = 0;
	cnt = 0;
	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] != '.')
			{
				cnt += ft_checktetri_sub(tab, i, j);
			}
			j++;
		}
		i++;
	}
	if (cnt != 6 && cnt != 8)
		ft_error(1);
	return (1);
}
