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
	// ft_strdel(&buf);
}

int copy_map(t_filler *f)
{
	char *line;
	int i;
	int j;
	FILE *ID = fopen("test.txt", "a");
	fprintf(ID,"in copy map\n");
	fclose(ID);
	f->init = 0;
	i = 0;
	if(!(f->map_tab = malloc(sizeof(int*) * f->map_x)))
		return(-1); // free f
	while(get_next_line(0, &line) > 0)
	{
		if(line)
		{
			if(line[0] == 'P' && line[1] == 'i')
				return(get_piece(f, line));
			if(!(f->map_tab[i]=malloc(sizeof(int*) * f->map_y)))
				return(-1);
			copy_map_bis(f, &i, line);
			ft_strdel(&line);
			i++;
		}
		else
			return(-1); // free what has been allocated before, line, map, f
	}
	return(0);
}

void copy_map_bis(t_filler *f, int *i, char *line)
{
	int j;

	j = 4;
	while(j < f->map_y + 4)
	{
		if((line[j] = ft_toupper(line[j])) == f->p1)
		{
				f->map_tab[*i][j - 4] = 1;
				if (f->first_p == 0)
				{
					f->first_p = 1;
					f->map_first_p = *i;
				}
		}
		if(line[j] == '.')
			f->map_tab[*i][j - 4] = 0;
		if((line[j] = ft_toupper(line[j])) == f->p2)
			f->map_tab[*i][j - 4] = 2;
		j++;
	}
}
