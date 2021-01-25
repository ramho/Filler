/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:46:45 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/07/17 17:48:22 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		get_player(t_filler *f)
{
	char	*buf;

	if (!(get_next_line(0, &buf)))
		return (-1);
	if (ft_strstr(buf, "p1"))
	{
		f->p1 = 'O';
		f->p2 = 'X';
	}
	else
	{
		f->p1 = 'X';
		f->p2 = 'O';
	}
	ft_strdel(&buf);
	return (0);
}

void	first_init(t_filler *f)
{
	f->init = 0;
	f->first_p = 0;
	f->switch_algo = 0;
}

int		main(void)
{
	t_filler	f;
	char		*buf;
	int			ret;

	if (get_player(&f) == -1)
		return (-1);
	first_init(&f);
	while ((ret = get_next_line(0, &buf)) > 0)
	{
		if (f.init == 0)
			re_init_struct(&f);
		if (buf[0] == 'P' && buf[1] == 'l')
			get_map(&f, buf);
		if (ft_strstr(buf, "   "))
		{
			ft_strdel(&buf);
			if (copy_map(&f) == -1)
				return (-1);
			ft_printf("%i %i\n", f.play_x, f.play_y);
		}
	}
	if (ret == -1)
		return (-1);
	return (0);
}
