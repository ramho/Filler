/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:46:36 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/07/17 17:46:38 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_digit(int *i, char *buf)
{
	int		ret;

	ret = ft_atoi(buf + *i);
	while (ft_isdigit(buf[*i]))
		*i = *i + 1;
	return (ret);
}

void	re_init_struct(t_filler *f)
{
	f->map_x = 0;
	f->map_y = 0;
	f->piece_x = 0;
	f->piece_y = 0;
	f->connexion = 0;
	f->play_x = 0;
	f->play_y = 0;
	f->map_tab = NULL;
	f->piece_tab = NULL;
	f->line = NULL;
	f->border_piece = 0;
	f->count = 0;
}

int		error_handle(int check, int size, t_filler *f)
{
	if (check == 1)
		free_tab(size, f->map_tab);
	if (check == 2)
	{
		ft_strdel(&f->line);
		free_tab(size, f->map_tab);
	}
	if (check == 3)
	{
		free_tab(f->map_x, f->map_tab);
		free_tab(f->piece_x, f->piece_tab);
	}
	if (check == 4)
	{
		free_tab(f->map_x, f->map_tab);
		free_tab(size, f->piece_tab);
		ft_strdel(&f->line);
	}
	if (check == 5)
	{
		free_tab(f->map_x, f->map_tab);
		free_tab(size, f->piece_tab);
	}
	ft_printf("0 0\n");
	return (-1);
}

void	free_tab(int size, int **tab)
{
	if (!tab)
		return ;
	while (--size >= 0)
		free(tab[size]);
	free(tab);
}
