/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:47:51 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/07/17 17:47:53 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		top_left_corner(t_filler *f)
{
	if (f->switch_algo == 0)
		return (algo_nw_se(f));
	if (f->switch_algo == 1)
		return (algo_se_nw(f));
	if (f->switch_algo == 2)
		return (algo_bottom_right(f));
	return (error_handle(3, 0, f));
}

int		top_right_corner(t_filler *f)
{
	if (f->switch_algo == 0)
		return (algo_ne_sw(f));
	if (f->switch_algo == 5)
		return (algo_sw_ne(f));
	if (f->switch_algo == 6)
		return (algo_top_left(f));
	return (error_handle(3, 0, f));
}

int		bottom_left_corner(t_filler *f)
{
	if (f->switch_algo == 0)
		return (algo_sw_ne(f));
	if (f->switch_algo == 7)
		return (algo_ne_sw(f));
	if (f->switch_algo == 8)
		return (algo_bottom_right(f));
	return (error_handle(3, 0, f));
}

int		bottom_right_corner(t_filler *f)
{
	if (f->switch_algo == 0)
		return (algo_se_nw(f));
	if (f->switch_algo == 3)
		return (algo_nw_se(f));
	if (f->switch_algo == 4)
		return (algo_top_left(f));
	return (error_handle(3, 0, f));
}

int		play(t_filler *f)
{
	if (f->map_first_px <= (f->map_x + 1) / 2 && f->map_first_py < f->map_y / 2)
		return (top_left_corner(f));
	if (f->map_first_px <= (f->map_x + 1) / 2 && f->map_first_py > f->map_y / 2)
		return (top_right_corner(f));
	if (f->map_first_px > (f->map_x + 1) / 2 && f->map_first_py <= f->map_y / 2)
		return (bottom_left_corner(f));
	if (f->map_first_px > (f->map_x + 1) / 2 && f->map_first_py > f->map_y / 2)
		return (bottom_right_corner(f));
	return (error_handle(3, 0, f));
}
