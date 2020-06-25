#include "filler.h"

int is_placable_piece(t_filler *f, int mx, int my)
{
	int x;
	int y;
	int my2;
  // printf("enter is placable piece\n");
  // FILE
	x = 0;
	y = 0;
	f->count = 0;
	while (x < f->piece_x)
	{
		my2 = my;
		y = 0;
		while (y < f->piece_y && my2 < f->map_y)
		{
			if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my2] == 1)
			{
				f->count += 1;
			}
			if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my2] == 2)
				return(0);
			if(f->count >= 2)
				return(0);
			y++;
			my2++;
		}
		x++;
		mx++;
	}
	if(f->count == 1)
	{
		return(1);
	}
	return(0);
}

int is_placable(t_filler *f)
{
	int x;
	int y;
  int ret = 0;
  // FILE *ID = fopen("test.txt", "a");
  // fprintf(ID, "enter is is_placable \n");
  // fclose(ID);
  // ft_printf("enter is placable \n");
	x = 0;
	y = 0;
	while(x < f->map_x)
	{
		y = 0;
		while(y < f->map_y)
		{
			if(is_placable_piece(f, x, y) == 1)
			{
        // ID = fopen("test.txt", "a");
        // fprintf(ID, "!!! placable \n");
        // fclose(ID);
				// printf("hello %d %d\n", x, y );
				f->play_x = x;
				f->play_y = y;
				// write(1,"2 2\n", 4);
				return(1);
			}
			y++;
		}
		x++;
		if(x == ((f->map_x - f->piece_x) + 1))
			return(0);
	}
	return(0);
}
