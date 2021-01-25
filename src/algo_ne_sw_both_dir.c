/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ne_sw_both_dir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:46:07 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/07/17 17:46:10 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		algo_ne_sw(t_filler *f)
{
	int		x;
	int		y;

	x = f->map_x - f->piece_x;
	while (x >= 0)
	{
		y = 0;
		while (y < f->map_y)
		{
			if (is_placable_piece(f, x, y) == 1)
				return (algo_ne_sw_result(f, x, y));
			y++;
		}
		x--;
	}
	return (error_handle(3, 0, f));
}

int		algo_ne_sw_result(t_filler *f, int x, int y)
{
	f->play_x = x;
	f->play_y = y;
	f->count++;
	if (((f->border_piece == 2 && x == f->map_x - f->piece_x)
				|| f->count > f->map_x) && f->switch_algo == 0)
		f->switch_algo = 5;
	if (((f->border_piece == 2 && x == f->map_x - f->piece_x)
				|| f->count > f->map_x) && f->switch_algo == 7)
		f->switch_algo = 8;
	free_tab(f->map_x, f->map_tab);
	free_tab(f->piece_x, f->piece_tab);
	return (1);
}

int		algo_sw_ne(t_filler *f)
{
	int		x;
	int		y;

	x = 0;
	while (x <= f->map_x - f->piece_x)
	{
		y = f->map_y - f->piece_y;
		while (y >= 0)
		{
			if (is_placable_piece(f, x, y) == 1)
				return (algo_sw_ne_result(f, x, y));
			y--;
		}
		x++;
	}
	return (error_handle(3, 0, f));
}

int		algo_sw_ne_result(t_filler *f, int x, int y)
{
	f->play_x = x;
	f->play_y = y;
	f->count++;
	if (((f->border_piece == 1 && x == 0) || f->count > f->map_x)
			&& f->switch_algo == 0)
		f->switch_algo = 7;
	if (((f->border_piece == 1 && x == 0) || f->count > f->map_x)
			&& f->switch_algo == 5)
		f->switch_algo = 6;
	free_tab(f->map_x, f->map_tab);
	free_tab(f->piece_x, f->piece_tab);
	return (1);
}
