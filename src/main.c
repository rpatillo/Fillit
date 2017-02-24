/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:18:20 by rpatillo          #+#    #+#             */
/*   Updated: 2016/04/25 15:10:33 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		ft_isfour(t_env *e)
{
	int		k;

	k = 0;
	while (e->split[k] != '\0')
	{
		if (ft_checktetri(e->split[k]) != 1)
			ft_error(2);
		k++;
	}
	ft_movetetri(e);
	ft_solve(e);
	ft_puttab(e->solu);
	return (0);
}

int		ft_checknewline(char *line)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	if ((len + 1) % 21 != 0)
		ft_error(1);
	while (line[j] != '\0')
	{
		if (line[j] == '\n' && line[j - 1] == '\n')
		{
			if (j != 20 && (j - 20) % 21 != 0)
				ft_error(1);
		}
		if (line[j] != '.' && line[j] != '#' && line[j] != '\n')
			ft_error(2);
		j++;
	}
	ft_checknewline2(line, len);
	return (0);
}

int		ft_checknewline2(char *line, int len)
{
	if ((line[0] != '.' && line[0] != '#') || (line[len - 2] == '\n' &&
	line[len - 1] == '\n'))
		ft_error(1);
	if ((line[len - 1] != '\n' && ft_strstr(line, "\n\n\n")))
		ft_error(1);
	return (0);
}

int		main(int ac, char **av)
{
/*	int		i;
	int		fd;
	t_env	e;
	char	line[BUFF_SIZE];
	char	**map;

	i = 0;
	if (av != 2)
	{
		ft_putendl("No fd found");
		return (0);
	}
	fd = open(ac[1], O_RDONLY);
	ft_bzero(line, BUFF_SIZE);
	read(fd, line, BUFF_SIZE);
	ft_checknewline(line);
	e.tab = ft_strsplit(line, '\n');
	while (e.tab[i++] != '\0')
		if ((e.blocknbr = i / 4) > 26)
			ft_error(2);
	ft_createtab(&e);
	ft_savetab(&e);
	ft_isfour(&e);
	close(fd);*/
	char *line;
    int    fd;

    if(!ac)
        return(0);
    fd = open(av[1], O_RDONLY);
    while (get_next_line(fd, &line) == 1)
    {
   //  ft_putstr("test : ");
        ft_putendl(line);
    }
    close(fd);
    return (0);
}
