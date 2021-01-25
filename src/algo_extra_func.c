/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_extra_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:45:27 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/07/17 17:49:07 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	init_is_placable(t_filler *f)
{
	f->x = 0;
	f->tot = 0;
	f->connexion = 0;
}

int		is_placable_piece(t_filler *f, int mx, int my)
{
	int		my2;

	init_is_placable(f);
	while (f->x < f->piece_x)
	{
		my2 = my;
		f->y = 0;
		while (f->y < f->piece_y && my2 < f->map_y)
		{
			if (f->piece_tab[f->x][f->y] == 1 && f->map_tab[mx][my2] == 1)
				f->connexion += 1;
			if (f->piece_tab[f->x][f->y] == 1 && f->map_tab[mx][my2] == 2)
				return (0);
			if (f->connexion >= 2)
				return (0);
			f->y++;
			my2++;
			f->tot++;
		}
		f->x++;
		mx++;
	}
	if (f->connexion == 1 && f->tot == f->piece_tot)
		return (1);
	return (0);
}

int		algo_top_left(t_filler *f)
{
	int		x;
	int		y;

	x = 0;
	while (x < f->map_x)
	{
		y = f->map_y / 2;
		while (y >= 0)
		{
			if (is_placable_piece(f, x, y) == 1)
			{
				f->play_x = x;
				f->play_y = y;
				free_tab(f->map_x, f->map_tab);
				free_tab(f->piece_x, f->piece_tab);
				return (1);
			}
			y--;
		}
		x++;
		if (x == ((f->map_x - f->piece_x) + 1))
			return (algo_ne_sw(f));
	}
	return (algo_ne_sw(f));
}

int		algo_bottom_right(t_filler *f)
{
	int		x;
	int		y;

	x = f->map_x - f->piece_x;
	while (x > 0)
	{
		y = f->map_y;
		while (y >= f->map_y / 2)
		{
			if (is_placable_piece(f, x, y) == 1)
			{
				f->play_x = x;
				f->play_y = y;
				free_tab(f->map_x, f->map_tab);
				free_tab(f->piece_x, f->piece_tab);
				return (1);
			}
			y--;
		}
		x--;
	}
	return (algo_se_nw(f));
}
