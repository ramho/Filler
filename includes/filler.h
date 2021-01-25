/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:46:55 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/07/17 17:46:57 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_filler
{
	char	p1;
	char	p2;
	int		init;
	char	*line;
	int		map_x;
	int		map_y;
	int		**map_tab;
	int		map_first_px;
	int		map_first_py;
	int		first_p;
	int		piece_x;
	int		piece_y;
	int		piece_tot;
	int		**piece_tab;
	int		border_piece;
	int		connexion;
	int		count;
	int		switch_algo;
	int		x;
	int		y;
	int		tot;
	int		play_x;
	int		play_y;
}				t_filler;

/*
** filler.c
*/
int				main(void);
void			first_init(t_filler *f);
int				get_player(t_filler *f);

/*
** map.c
*/
void			get_map(t_filler *f, char *line);
int				copy_map(t_filler *f);
void			copy_map_bis(t_filler *f, int *i, char *line);

/*
** piece.c
*/
int				get_piece(t_filler *f, char *buf);
int				copy_piece(t_filler *f);
void			copy_piece_bis(t_filler *f, int *i, char *line);

/*
** play.c
*/
int				play(t_filler *f);
int				top_left_corner(t_filler *f);
int				top_right_corner(t_filler *f);
int				bottom_left_corner(t_filler *f);
int				bottom_right_corner(t_filler *f);

/*
** algo_nw_se_both_dir.c
*/
int				algo_nw_se(t_filler *f);
int				algo_nw_se_result(t_filler *f, int x, int y);
int				algo_se_nw(t_filler *f);
int				algo_se_nw_result(t_filler *f, int x, int y);

/*
** algo_ne_sw_both_dir.c
*/
int				algo_ne_sw(t_filler *f);
int				algo_ne_sw_result(t_filler *f, int x, int y);
int				algo_sw_ne(t_filler *f);
int				algo_sw_ne_result(t_filler *f, int x, int y);

/*
** algo_extra_func.c
*/
void			init_is_placable(t_filler *f);
int				is_placable_piece(t_filler *f, int mx, int my);
int				algo_top_left(t_filler *f);
int				algo_bottom_right(t_filler *f);

/*
** extra_func.c
*/
int				get_digit(int *i, char *buf);
void			re_init_struct(t_filler *f);
int				error_handle(int check, int size, t_filler *f);
void			free_tab(int size, int **tab);

#endif
