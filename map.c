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
	int i;
	int j;
	int ret;

	f->init = 0;
	i = 0;
	if (!(f->map_tab = malloc(sizeof(int*) * f->map_x)))
		return (-1);
	while ((ret = get_next_line(0, &f->line)) > 0)
	{
			if (f->line[0] == 'P' && f->line[1] == 'i')
				return (get_piece(f, f->line));
			if (!(f->map_tab[i] = malloc(sizeof(int*) * f->map_y)))
				return (error_handle(2, i, f));
			copy_map_bis(f, &i, f->line);
			ft_strdel(&f->line);
			i++;
		}
	if (ret <= 0)
		return (error_handle(1,i,f));
	return (error_handle(1,i,f));
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
				f->map_first_px = *i;
				f->map_first_py = j - 4;
			}
		}
		else if (line[j] == '.')
			f->map_tab[*i][j - 4] = 0;
		else if (line[j] == f->p2)
			f->map_tab[*i][j - 4] = 2;
		j++;
	}
}
