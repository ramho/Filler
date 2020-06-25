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
			f->map_y=get_digit(&i, buf);
		i++;
	}
	f->init = 1;
	// ft_strdel(&buf);
}

int copy_map(t_filler *f)
{
	char *line;
	int i;
	int j;
	int count;

	f->init = 0;

	i = 0;
	count = 0;
	if(!(f->piece_tab = malloc(sizeof(int*) * f->piece_x)))
		return(-1); // free f
	while(get_next_line(0, &line) > 0)
	{
		if(line)
		{
			if(ft_strstr(line, "Piece"))
			{
				count = 1;
				return(get_piece(f, line));
			}
			if(!(f->map_tab[i]=malloc(sizeof(int*) * f->map_y)))
				return(-1);
			j = 4;
			while((j < f->map_y + 4) && count == 0 )
			{
				if((line[j] = ft_toupper(line[j])) == f->p1)
					f->map_tab[i][j - 4] = 1;
				if(line[j] == '.')
					f->map_tab[i][j - 4] = 0;
				if((line[j] = ft_toupper(line[j])) == f->p2)
					f->map_tab[i][j - 4] = 2;
				j++;
			}
			// ft_strdel(&line);
			i++;
		}
		else
			return(-1); // free what has been allocated before, line, map, f
	}
	return(0);
}
