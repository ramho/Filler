
#include "filler.h"

int		get_piece(t_filler *f, char *buf)
{
	// ft_printf("enter get piece %s\n", buf);
	int i;
	int x;
	// FILE *ID = fopen("test.txt", "a");
	// fprintf(ID, "enter get piece\n");
	// fclose(ID);
	x = 0;
	i = 0;
	while (i < ft_strlen(buf))
	{
		if (ft_isdigit(buf[i]) && x == 0)
		{
			x = 1;
			f->piece_x=get_digit(&i, buf);
		}
		if (ft_isdigit(buf[i]) && x == 1)
			f->piece_y=get_digit(&i, buf);
		i++;
	}
	copy_piece(f);
	return(0);
}

int copy_piece(t_filler *f)
{
	int i;
	int j;
	char *line;
	// ft_printf("enter copy piece %d %d\n", f->piece_x, f->piece_y);
	// FILE *ID = fopen("test.txt", "a");
	// fprintf(ID, "enter copy piece\n");
	// fclose(ID);
	i = 0;
	if(!(f->piece_tab = malloc(sizeof(int*) * f->piece_x)))
		return(-1);
	while(get_next_line(0, &line) >= 0)
	{

		if (line)
		{
			// ft_printf("enter piece line %s\n", line);
			if(!(f->piece_tab[i]=malloc(sizeof(int*) * f->piece_y)))
				return(-1);
			j = 0;
			while(j < f->piece_y)
			{
				if(line[j] == '*')
					f->piece_tab[i][j] = 1;
				else if (line[j] == '.')
					f->piece_tab[i][j] = 0;
				j++;
			}
			i++;
			// printf(" i = %d\n", i);
			if (i == (f->piece_x))
			{
				return(is_placable(f));
			}
		}
	}
	return(0);
}
