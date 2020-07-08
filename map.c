#include "filler.h"

void get_map(t_filler *f, char *buf)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < ft_strlen(buf))
	{
		if (ft_isdigit(buf[i]) && x == 0)
		{
			x = 1;
			f->map_x=get_digit(&i, buf);
		}
		if (ft_isdigit(buf[i]) && x == 1)
			f->map_y = get_digit(&i, buf);
		i++;
	}
	f->init = 1;
	ft_strdel(&buf);
}

int copy_map(t_filler *f)
{
	char *line;
	int i;
	int j;

	f->init = 0;
	i = 0;
	if (!(f->map_tab = malloc(sizeof(int*) * f->map_x)))
		return (error_handle(f));
	f->opp_piece = malloc(sizeof(int) * f->map_x * f->map_y);

	while (get_next_line(0, &line) > 0)
	{
		if (line)
		{
			if (line[0] == 'P' && line[1] == 'i')
				return (get_piece(f, line));
			if (!(f->map_tab[i] = malloc(sizeof(int*) * f->map_y)))
				return (error_handle(f)); // free line
			copy_map_bis(f, &i, line);
			ft_strdel(&line);
			i++;
		}
		else
			return (error_handle(f));
	}
	return (0);
}

void copy_map_bis(t_filler *f, int *i, char *line)
{
	int j;

	j = 4;
	while(j < f->map_y + 4)
	{
		if (line[j] == f->p1)
		{
			f->map_tab[*i][j - 4] = 1;
			if (f->first_p == 0)
			{
				f->first_p = 1;
				f->map_first_p = *i;
			}
		}
		else if (line[j] == '.')
			f->map_tab[*i][j - 4] = 0;
		else if (line[j] == f->p2)
		{
			f->map_tab[*i][j - 4] = 2;
			f->opp_piece[f->o] = *i + (j - 4);
			f->o++;
		}
		j++;
	}
	sort_int_tab(f->opp_piece, f->o);
}
