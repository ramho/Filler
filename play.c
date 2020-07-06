#include "filler.h"

int is_placable_piece(t_filler *f, int mx, int my)
{
	int x;
	int y;
	int my2;
	int tot;

	x = 0;
	y = 0;
	tot = 0;
	f->count = 0;
	while (x < f->piece_x)
	{
		my2 = my;
		y = 0;
		while (y < f->piece_y && my2 < f->map_y)
		{
				if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my2] == 1)
					f->count += 1;
				if(f->piece_tab[x][y] == 1 && f->map_tab[mx][my2] == 2)
					return(0);
				if(f->count >= 2)
					return(0);
			y++;
			my2++;
			tot++;
		}
		x++;
		mx++;
	}
	if(f->count == 1 && tot == f->piece_tot)
		return(1);
	return(0);
}

int algo_go_north(t_filler *f)
{
	int x;
	int y;
	FILE *ID;

	x = 0;
	while(x < f->map_x)
	{
		y = 0;
		while(y < f->map_y)
		{
			if(is_placable_piece(f, x, y) == 1)
			{
				f->play_x = x;
				f->play_y = y;
				// if(x < f->map_x * 0.1 )
				// 	f->switch_algo = 1;
				return(1);
			}
			y++;
		}
		x++;
		if(x == ((f->map_x - f->piece_x) + 1))
			return(error_handle(f));
	}
	return(error_handle(f));
}

int algo_go_south(t_filler *f)
{
	int x;
	int y;

	x = f->map_x - f->piece_x;
	while(x >= 0)
	{
		y = f->map_y - f->piece_y;
		while(y >= 0)
		{
			if(is_placable_piece(f, x, y) == 1)
			{
				f->play_x = x;
				f->play_y = y;
				// if(x > f->map_x * 0.9)
				// 	f->switch_algo = 1;
				return(1);
			}
			y--;
		}
		x--;
	}
	return(error_handle(f));
}


int play(t_filler *f)
{
	if ((f->map_first_p < (f->map_x + 1) / 2) && f->switch_algo == 0)
			return(algo_go_south(f));
	if ((f->map_first_p < (f->map_x + 1) / 2) && f->switch_algo == 1)
			return(algo_go_north(f));
	if ((f->map_first_p >= (f->map_x + 1) / 2) && f->switch_algo == 0)
		return(algo_go_north(f));
	if ((f->map_first_p >= (f->map_x + 1) / 2) && f->switch_algo == 1)
			return(algo_go_south(f));
	return(error_handle(f));
}
