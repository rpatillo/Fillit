/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:21:18 by rpatillo          #+#    #+#             */
/*   Updated: 2016/04/25 15:39:07 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include "struct.h"

int		ft_checknewline(char *line);
int		ft_checknewline2(char *line, int len);
int		ft_isfour(t_env *e);

int		ft_createtab(t_env *e);
int		ft_savetab(t_env *e);
char	ft_savechar(char src, int i);
int		ft_checktetri(char **tab);
int		ft_checktetri_sub(char **tab, int i, int j);

int		ft_place(t_env *e, int size);
int		ft_putleft(t_env *e, int num, int x, int y);
int		ft_putpiece(t_env *e, int num, int x, int y);
int		ft_sqrt(t_env *e);

int		ft_recursolve(t_env *e, int num, int size);
int		ft_solve(t_env *e);

int		ft_movetetri(t_env *e);
int		ft_movetetri_sub(char **tab, t_env *e);
int		ft_movetetri_sub2(char **tab, t_env *e);

int		ft_error(int x);
int		ft_isreturn(t_env *e);
int		ft_sizetetri_l(t_env *e, int num);
int		ft_sizetetri_h(t_env *e, int num);

#endif
