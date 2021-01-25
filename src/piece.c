/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:47:43 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/07/17 17:47:45 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_piece(t_filler *f, char *buf)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (i < ft_strlen(buf))
	{
		if (ft_isdigit(buf[i]) && x == 0)
		{
			x = 1;
			f->piece_x = get_digit(&i, buf);
		}
		if (ft_isdigit(buf[i]) && x == 1)
			f->piece_y = get_digit(&i, buf);
		i++;
	}
	ft_strdel(&buf);
	f->piece_tot = f->piece_x * f->piece_y;
	return (copy_piece(f));
}

int		copy_piece(t_filler *f)
{
	int		i;
	int		ret;

	i = 0;
	if (!(f->piece_tab = malloc(sizeof(int*) * f->piece_x)))
		return (error_handle(1, 0, f));
	while ((ret = get_next_line(0, &f->line)) >= 0)
	{
		if (!(f->piece_tab[i] = malloc(sizeof(int*) * f->piece_y)))
			return (error_handle(4, i, f));
		copy_piece_bis(f, &i, f->line);
		i++;
		if (i == (f->piece_x))
			return (play(f));
	}
	if (ret <= 0)
		return (error_handle(5, i, f));
	return (error_handle(5, i, f));
}

void	copy_piece_bis(t_filler *f, int *i, char *line)
{
	int		j;

	j = 0;
	while (j < f->piece_y)
	{
		if (line[j] == '*')
		{
			f->piece_tab[*i][j] = 1;
			if (*i == 0)
				f->border_piece = 1;
			if (*i == f->piece_x - 1)
				f->border_piece = 2;
		}
		else if (line[j] == '.')
			f->piece_tab[*i][j] = 0;
		j++;
	}
	ft_strdel(&line);
}
